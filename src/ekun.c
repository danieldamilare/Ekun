#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <signal.h>
#include "ekparser.h"
#include "dbg.h"
#include "eklex.h"
#include "y.tab.h"
#include <unistd.h>
#include "ekmem.h"
#include "ekvm.h"

#include "ekun.h"

EkGstate ek_state;


void tokenize(char * source){
    Token tok;
        int start_pos;

        while(1){
            tok = get_token();

            if(tok.token_type == EKEOF)
                break;
            else{
                start_pos = tok.start - source;
                printf("%d,%d-%d,%d:\t", (tok.token_type == NEWLINE ?tok.line -1: tok.line), start_pos,
                        tok.line, start_pos+tok.length);
                print_type(tok.token_type);
                if(tok.token_type == NEWLINE)
                    printf("\t'\\n'\n");
                else
                    printf( "\t'%.*s'\n", tok.length, tok.start);
            }
        }

}


void interpret(char * source){
    DEBUG_PRINT("in Interpreter");
    init_lexer(source);
    initialize_code();
    //doing nothing for now just tokenizing
    if(IS_SET_OPT(OPT_TOKENIZE)){
        DEBUG_PRINT("Tokenize option set");
        tokenize(source);
    }
    else if(IS_SET_OPT(OPT_DISASSEMBLE) && 
            !IS_SET_OPT(OPT_TOKENIZE)){
            DEBUG_PRINT("Dump option set");
            printf("Dumping...\n");
    }
    else {
        if(compile() == 0){
            vm_run();
        }
    }
}


static char * read_file(char *filename){
    DEBUG_PRINT("iN read_file");
    FILE *file = fopen(filename, "rb");

    if(!file){
        fprintf(stderr, "Could not read file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    char * source = ek_malloc(file_size + 1);

    if(fread(source, sizeof(char), file_size, file) < file_size){
        fprintf(stderr, "Could not read '%s'.\n", filename);
        exit(1);
    }
    source[file_size] = '\0';
    fclose(file);
    return source;
}


static void usage(void){
    fprintf(stderr, "Usage: ekun [Options] [file]\n"
            "Options:\n"
            "  -t  --tokenize: Display token from source coden\n"
            "  -d  --dump: Show assembler-like listing of program and exit\n"
            "  -h  --help: show program usage\n");
}


static void process_option(int argc, char ** argv){
    DEBUG_PRINT("In process_option");
    //skip program name
    argc--;
    argv++; 
    int set_file = 0;
    char * word;

    for (int i = 0;  i < argc; argv++, i++){
        word = *argv;

        if (*word == '-'){
            if (CMP_EQUAL(word, "-t") || CMP_EQUAL(word, "--tokenize"))
                SET_OPT(OPT_TOKENIZE);
            else if (CMP_EQUAL(word, "-d") || CMP_EQUAL(word, "--dump"))
                SET_OPT(OPT_DISASSEMBLE);
            else if ( CMP_EQUAL(word, "-h") || CMP_EQUAL(word, "--help")){
                usage();
                exit(1);
            }

            else{
                fprintf(stderr, "%s: Unrecognized option: %s\n",
                        ek_state.progname, word);
                usage();
                exit(1);
            }
        }
        else if(set_file == 0){
            ek_state.filename = word;
            set_file = 1;
        }
    }
}


static void init_state(void){
    DEBUG_PRINT("in init_state");
    ek_state.filename = NULL;
    ek_state.file_handler = NULL;
    ek_state.line_no = 1;
    ek_state.has_error = false;
    ek_state.options = 0;
    ek_state.interactive = false;
}


void ek_sig_handler(int sig){
    DEBUG_PRINT("In signal handler");

    switch(sig){
        case SIGFPE:
            signal(SIGFPE, ek_sig_handler);
            EK_ERROR(ek_state.line_no, "Floating point exception");
    }
}


static void repl(void){
    DEBUG_PRINT("In repl");
    if(isatty(fileno(stdin))){
        ek_state.interactive = true;
        char * Welcome_message = "E KAABO!\n"
            "Programming ni ede Yoruba "
            "(C) 2024";
        printf("%s\n", Welcome_message);
    }
    for(;;){
        char * line = NULL;
        size_t char_no = 0;
        if(ek_state.interactive)
            printf("> ");
        if(getline(&line, &char_no, stdin) == -1){
            EK_FREE(line);
            putchar('\n');
            break;
        }
        interpret(line);
        EK_FREE(line);
    }
}


static void run(void){
    DEBUG_PRINT("In run");

    if(ek_state.filename){
        char *source = read_file(ek_state.filename);
        interpret(source);
        EK_FREE(source);
    }
    else {
        repl();
    }
}


int main(int argc, char ** argv){
    init_state();
    vm_init();
    ek_state.progname = *argv; 
    process_option(argc, argv);
    run();
    if(ek_state.has_error){
        EK_ERROR(ek_state.line_no, "Unknown Error");
        exit(64);
    }
    vm_cleanup();
    exit(0);
}
