# Makefile cho RTE

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -I ../Common -I Inc
SRCS = Src/Rte_Can.c Src/Rte_Dem.c Src/Rte_FIControl.c Src/Rte_NvM.c Src/Rte_CalibPara.c Src/Rte_WdgM.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ../obj/RTE

.PHONY: all clean

all: $(OBJS)

$(OBJ_DIR)/%.o: Src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist ../obj/RTE\*.o (del /S /Q ../obj/RTE\*.o 2>nul) else (echo No files to delete)

