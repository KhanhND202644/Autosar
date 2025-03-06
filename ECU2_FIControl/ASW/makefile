# Makefile for Application Software (ASW)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -I ../RTE/Inc -I ../../Common -I Inc
SRCS = Src/FIControlSWC.c Src/CalibParaSWC.c Src/NvMBlockSWC.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ../obj/ASW

.PHONY: all clean

all: $(OBJS)

$(OBJ_DIR)/%.o: Src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist "..\obj\ASW" del /S /Q ..\obj\ASW\*.o 2>nul
