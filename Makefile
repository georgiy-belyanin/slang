INCLUDE_DIR=include
INCLUDE_PATH=$(INCLUDE_DIR)/
LIB_DIR=lib
LIB_PATH=$(LIB_DIR)/

CC=gcc
CFLAGS=-I$(INCLUDE_DIR) $(shell llvm-config --cflags) -g -O0
LD=gcc
LDFLAGS=$(shell llvm-config --ldflags --libs) -g -O0

SRC_DIR=src
SRC_PATH=$(SRC_DIR)/
SRC_FILES=$(wildcard $(SRC_PATH)*.c) $(wildcard $(SRC_PATH)*/*.c) $(wildcard $(SRC_PATH)*/*/*.c) $(wildcard $(SRC_PATH)*/*/*/*.c)

TMP_DIR=tmp
TMP_PATH=$(TMP_DIR)/
TMP_FILES=$(patsubst $(SRC_PATH)%.c,$(TMP_PATH)%.o,$(SRC_FILES))

BIN_DIR=bin
BIN_PATH=$(BIN_DIR)/

EXE_NAME=slang
EXE_FILE=$(BIN_PATH)$(EXE_NAME)

MAIN_NAME=main.c
MAIN_PATH=$(SRC_PATH)$(MAIN_NAME)
MAIN_TMP=$(patsubst $(SRC_PATH)%.c,$(TMP_PATH)%.o,$(MAIN_PATH))

TESTS_DIR=tests
TESTS_PATH=$(TESTS_DIR)/
TESTS_MAIN_NAME=main_tests.c
TESTS_MAIN_PATH=$(TESTS_PATH)$(TESTS_MAIN_NAME)
TESTS_MAIN_TMP=$(patsubst $(TESTS_PATH)%.c,$(TMP_PATH)%.o,$(TESTS_MAIN_PATH))

TESTS_TMP_FILES=$(subst $(MAIN_TMP),$(TESTS_MAIN_TMP),$(TMP_FILES))

TESTS_EXE_NAME=slang_tests
TESTS_EXE_FILE=$(BIN_PATH)$(TESTS_EXE_NAME)

all: clean $(EXE_FILE)
tests: clean $(TESTS_EXE_FILE)
	@$(TESTS_EXE_FILE)
clean:
	@echo Cleaning up...
	@-rm -r $(TMP_PATH)

$(EXE_FILE): $(TMP_FILES)
	$(LD) $(LDFLAGS) -o $@ $^
$(TESTS_EXE_FILE): $(TESTS_TMP_FILES)
	$(LD) $(LDFLAGS) -o $@ $^

$(TMP_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
$(TMP_PATH)%.o: $(TESTS_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
