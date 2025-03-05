# Compiler and flags
CC = gcc
INCLUDES = -I . -I BSW/Inc/Services/ -I RTE/Inc/ -I Common/ -I BSW/Inc/MCAL/ -I ASW/Inc/ -I BSW/Inc/ECU_Abstraction
CFLAGS = -Wall -Wextra -std=c99 -g $(INCLUDES)

# Directories
SRC_DIRS = ASW/Src BSW/Src/Services BSW/Src/MCAL BSW/Src/ECU_Abstraction RTE/Src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(patsubst %, %/*.c, $(SRC_DIRS))) main.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/ECU2_FIControl

# Ensure directories exist before building
$(shell if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)")
$(shell if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)")

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)


$(OBJ_DIR)/%.o: %.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	@if exist "$(OBJ_DIR)" rmdir /S /Q "$(OBJ_DIR)"
	@if exist "$(BIN_DIR)" rmdir /S /Q "$(BIN_DIR)"

.PHONY: all clean
