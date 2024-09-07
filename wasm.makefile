CC = emcc
CFLAGS = -Wall -Wextra -g
PROFFLAG = -p
LDFLAGS = -O3 -s NO_EXIT_RUNTIME=1 -s ENVIRONMENT=web -s EXPORTED_FUNCTIONS="['_run_from_js', '_disassemble_from_js']" -s EXPORTED_RUNTIME_METHODS="['cwrap', 'addFunction']" -s ALLOW_TABLE_GROWTH=1 
DEBUG_FLAGS = -DDEBUG
WASM_DIR = EKUN_WASM

SRC_DIR = $(WASM_DIR)
OBJ_DIR = $(WASM_DIR)/obj
PARSER_C = $(WASM_DIR)/ekparser.c
PARSER_SRC = $(WASM_DIR)/ekparser.y
PARSER_OBJ = $(OBJ_DIR)/ekparser.o
SRCS = $(wildcard $(WASM_DIR)/*.c)
HEADERS = $(wildcard $(WASM_DIR)/*.h)
OBJS = $(patsubst $(WASM_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = ./static/ekun.js

.PHONY: all clean

all: gen_wasm $(PARSER_OBJ) $(TARGET)

gen_wasm:
	@./gen_wasm.sh || { echo "Failed to generate WASM files"; exit 1; }

$(PARSER_OBJ): $(PARSER_SRC)
	@mkdir -p $(OBJ_DIR)
	cd $(SRC_DIR) && yacc -d -t ekparser.y
	mv $(SRC_DIR)/y.tab.c $(SRC_DIR)/ekparser.c
	$(CC) -O3 -c $(SRC_DIR)/ekparser.c $(CFLAGS) -o $(OBJ_DIR)/ekparser.o

$(TARGET): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)
	@echo "done here"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(SRC_DIR)/ekparser.c $(SRC_DIR)/y.tab.h

