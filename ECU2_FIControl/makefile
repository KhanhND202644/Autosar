# Compiler and flags
CC = gcc
INCLUDES = -I . -I BSW/Inc/Services/ -I RTE/ -I RTE/Inc/
CFLAGS = -Wall -Wextra -Werror -std=c99 -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC_FILES = \
    main.c \
    OS/Os.c \
    AWS/FIControlSWC.c \
    AWS/NvMBlockSWC.c \
    AWS/CalibParaSWC.c \
    RTE/Rte_FIControl.c \
    RTE/Rte_CanCom.c \
    RTE/Rte_DEM.c \
    RTE/Rte_NvM.c \
    RTE/Rte_WdgM.c \
    RTE/Rte_CalibPara.c \
    BSW/Service/CanIf.c \
    BSW/Service/ComHwAb_Can.c \
    BSW/Service/WdgIf.c \
    BSW/Service/NvM.c \
    BSW/Service/MemIf.c \
    BSW/Service/Dem.c \
    MCAL/CanDrv.c \
    MCAL/FlashDrv.c \
    MCAL/WdgDrv.c \

# Object files
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Output binary
TARGET = $(BIN_DIR)/ECU2_FIControl

# Create necessary directories
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default rule
all: $(TARGET)

# Compile and link
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

# Compile each source file
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: all clean
