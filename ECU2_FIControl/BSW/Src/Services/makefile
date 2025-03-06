# Makefile cho Services

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -I ../../../Common -I ../../Inc/Services
SRCS = Can.c Dem.c NvM.c Os.c WdgIf.c MemIf.c
SRC_FILES += $(BSW_SRC_PATH)/../InjectorCDD.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ../../obj/BSW/Services

.PHONY: all clean

all: $(OBJS)

$(OBJ_DIR)/%.o: Src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist ../../obj/BSW/Services\*.o (del /S /Q ../../obj/BSW/Services\*.o 2>nul) else (echo No files to delete)


