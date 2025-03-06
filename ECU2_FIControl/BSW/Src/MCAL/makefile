# Makefile cho MCAL

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -I ../../../Common -I ../../../ECU2_FIControl/Common -I ../../Inc/MCAL
SRCS = CanDrv.c FlashDrv.c WdgDrv.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ../../obj/BSW/MCAL

.PHONY: all clean

all: $(OBJS)

$(OBJ_DIR)/%.o: Src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist ../../obj/BSW/MCAL\*.o (del /S /Q ../../obj/BSW/MCAL\*.o 2>nul) else (echo No files to delete)

