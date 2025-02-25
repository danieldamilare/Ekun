#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <signal.h>
#include <stdarg.h>
#include "ekparser.h"
#include "dbg.h"
#include "eklex.h"
#include "y.tab.h"
#include <unistd.h>
#include "ekmem.h"
#include "ekvm.h"

#include "ekun.h"
#include <emscripten.h>

EkGstate ek_state;

void disassemble(void);
void custom_printf(const char *format, ...) {
        // Call JavaScript function to update div content
#if defined(EMSCRIPTEN)
    va_list args;
    va_start(args, format);
    int len =  vsnprintf(NULL, 0, format, args);
    va_end(args);
    char * buffer = malloc(len+1);
    if(!buffer){
        return;
    }
    va_start(args, format);
    vsnprintf(buffer, len + 1, format, args);
    va_end(args);
    EM_ASM_({
        document.getElementById('output').innerText += UTF8ToString($0);
    }, buffer);
    free(buffer);
#else
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
#endif
}



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


void interpret(char * source, int disassemble_flag){
    DEBUG_PRINT("in Interpreter");
    init_lexer(source);
    initialize_code();

    if(compile() == 0){
        if(disassemble_flag)
            disassemble();
        else
            vm_run();
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

const char * run_from_js(const char * source){
    //initialize interpreter state
    init_state();
    vm_init();
    interpret((char *)source, 0);
    vm_cleanup();
    return "";
}

void disassemble_from_js(const char * source){
    init_state();
    vm_init();
    interpret((char *)source, 1);
    vm_cleanup();
}

