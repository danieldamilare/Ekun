#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <signal.h>
#include "dbg.h"
#include "eklex.h"
#include "ekparser.h"
#include "ekmem.h"
#include "ekun.h"

EkGstate ek_state;


void interpret(char * source){
    DEBUG_PRINT("in Interpreter");
    init_lexer(source);
    DEBUG_PRINT("lexer current: %s", lex->current);
    DEBUG_PRINT("lexer start: %s", lex->start);
    DEBUG_PRINT("lexer line_no: %d", lex->line_no);

    //doing nothing for now just tokenizing
    if(ek_state.options & OPT_TOKENIZE){
        DEBUG_PRINT("Tokenize option set");
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
    else if(( ek_state.options & OPT_DISASSEMBLE ) && 
            !(ek_state.options & OPT_TOKENIZE)){
            DEBUG_PRINT("Dump option set")
            printf("Dumping...\n");
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


static void usage(){
    fprintf(stderr, "Usage: ekun [Options] [file]\n"
            "Options:\n"
            "  -t  --tokenize: Display token from source coden\n"
            "  -d  --dump: Show assembler-like listing of program and exit\n"
            "  -h  --help: show program usage\n");
}


static void set_option(int argc, char ** argv){
    DEBUG_PRINT("In set_option");
    //skip program name
    argc--;
    argv++; 
    int set_file = 0;
    char * word;

    for (int i = 0;  i < argc; argv++, i++){
        word = *argv;

        if (*word == '-'){
            if (strcmp(word, "-t") == 0 ||
                    strcmp(word, "--tokenize") == 0)
                ek_state.options |= OPT_TOKENIZE;
            else if (strcmp(word, "-d") == 0 || 
                    strcmp(word, "--dump") == 0)
                ek_state.options |= OPT_DISASSEMBLE;
            else if ( strcmp(word, "-h") == 0 ||
                    strcmp(word, "--help") == 0){
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
        }
    }
}


static void init_state(){
    DEBUG_PRINT("in init_state");
    ek_state.filename = NULL;
    ek_state.file_handler = NULL;
    ek_state.line_no = 1;
    ek_state.has_error = false;
    ek_state.options = 0;
}


void ek_sig_handler(int sig){
    DEBUG_PRINT("In signal handler");

    switch(sig){
        case SIGFPE:
            signal(SIGFPE, ek_sig_handler);
            ek_error(ek_state.line_no, "Floating point exception");
    }
}


static void repl(){
    DEBUG_PRINT("In repl");

    for(;;){
        char * line = NULL;
        size_t char_no = 0;
        if(getline(&line, &char_no, stdin) == -1){
            exit(1);
        }
        interpret(line);
        ek_free(line);
    }
}


static void run(void){
    DEBUG_PRINT("In run");

    if(ek_state.filename){
        char *source = read_file(ek_state.filename);
        interpret(source);
        ek_free(source);
    }
    else {
        repl();
    }
}


int main(int argc, char ** argv){
    init_state();
    ek_state.progname = *argv; 
    set_option(argc, argv);
    run();

    if(ek_state.has_error){
        ek_error(ek_state.line_no, "Unknown Error");
        exit(64);
    }
    exit(0);
}
