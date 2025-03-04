# Compiler and flags
CC = gcc
INCLUDES = -I . -I BSW/Inc/Services/ -I RTE/Inc/ -I Common/
CFLAGS = -Wall -Wextra -Werror -std=c99 -g $(INCLUDES)

# Directories
SRC_DIRS = ASW/Src BSW/Src/Services MCAL RTE/Src
OBJ_DIR = obj
BIN_DIR = bin

# Tự động tìm tất cả các file .c trong thư mục nguồn
SRCS = $(wildcard $(patsubst %, %/*.c, $(SRC_DIRS))) main.c

# Chuyển đổi danh sách SRCS thành danh sách OBJS
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Định nghĩa tệp nhị phân đầu ra
TARGET = $(BIN_DIR)/ECU2_FIControl

# Tạo thư mục nếu chưa có
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Quy tắc mặc định
all: $(TARGET)

# Quy tắc biên dịch nhị phân
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Quy tắc biên dịch từng file .c thành .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: all clean
