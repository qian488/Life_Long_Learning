# 定义编译器
CC = gcc

# 定义编译选项，添加了忽略未使用参数的选项
CFLAGS = -g -O0 -std=c11 -Wall -Werror -Wextra -Wno-unused-parameter

# 定义链接选项
LDFLAGS = -lm

# 定义目标文件
TARGET = filter

# 定义源文件
SOURCES = filter.c helpers.c

# 定义对象文件
OBJECTS = $(SOURCES:.c=.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# 编译源文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(OBJECTS) $(TARGET)

# 伪目标，用于防止与同名文件冲突
.PHONY: all clean