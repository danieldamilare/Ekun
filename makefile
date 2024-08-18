CC = gcc
CFLAGS = -Wall -Wextra -pedantic -lm -g -p
DEBUG_FLAGS = -DDEBUG
SRC_DIR = ./src
OBJ_DIR = ./obj
TARGET = ekun
SRCS = $(wildcard $(SRC_DIR)/*.c)
HEADERS = $(wildcard $(SRC_DIR)/*.h)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
PARSER_SRC = $(SRC_DIR)/ekparser.y
PARSER_C = $(SRC_DIR)/ekparser.c
PARSER_H = $(SRC_DIR)/y.tab.h
PARSER_OBJ = $(OBJ_DIR)/ekparser.o

# Add the parser object to the list of objects
OBJS := $(filter-out $(OBJ_DIR)/ekparser.o, $(OBJS))
OBJS += $(PARSER_OBJ)

.PHONY: all debug clean

all: $(PARSER_OBJ) $(TARGET)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all

$(PARSER_OBJ): $(PARSER_SRC)
	@mkdir -p $(OBJ_DIR)
	cd $(SRC_DIR) && yacc -d ekparser.y
	mv $(SRC_DIR)/y.tab.c $(SRC_DIR)/ekparser.c
	$(CC) -c $(SRC_DIR)/ekparser.c $(CFLAGS) -o $(OBJ_DIR)/ekparser.o

$(TARGET): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(SRC_DIR)/ekparser.c $(SRC_DIR)/y.tab.h

