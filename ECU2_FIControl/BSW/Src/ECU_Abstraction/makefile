# Makefile cho ECU Abstraction

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -I ../../Common -I ../../Inc/ECU_Abstraction
SRCS = ComHwAb_Can.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ../../obj/BSW/ECU_Abstraction

.PHONY: all clean

all: $(OBJS)

$(OBJ_DIR)/%.o: Src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist ../../obj/BSW/ECU_Abstraction\*.o (del /S /Q ../../obj/BSW/ECU_Abstraction\*.o 2>nul) else (echo No files to delete)
