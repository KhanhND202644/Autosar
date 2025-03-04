# Compiler and flags
CC = gcc
INCLUDES = -I . -I BSW/Inc/Services/ -I RTE/Inc/ -I Common/
CFLAGS = -Wall -Wextra  -std=c99 -g $(INCLUDES)

# Directories
SRC_DIRS = ASW/Src BSW/Src/Services MCAL RTE/Src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(patsubst %, %/*.c, $(SRC_DIRS))) main.c RTE/Src/Rte_Can.c


OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))


TARGET = $(BIN_DIR)/ECU2_FIControl


$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))


all: $(TARGET)


$(TARGET): $(OBJS) BSW/Src/MCAL/CanDrv.o BSW/Src/MCAL/FlashDrv.o BSW/Src/MCAL/WdgDrv.o obj/RTE/Src/Rte_Can.o
	$(CC) $(CFLAGS) -o $@ $(OBJS)


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: all clean
