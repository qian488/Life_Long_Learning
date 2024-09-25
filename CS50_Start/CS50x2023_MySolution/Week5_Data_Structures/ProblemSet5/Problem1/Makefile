# 定义编译器
CC=gcc

# 定义编译选项，-g 用于调试，-Wall 显示所有警告
CFLAGS=-g -Wall

# 定义链接选项
LDFLAGS += -lwinmm

# 定义需要的源文件
SOURCES=dictionary.c speller.c

# 定义生成的目标文件
OBJECTS=$(SOURCES:.c=.o)

# 定义最终的可执行文件名
EXEC=speller

# 默认目标
all: $(EXEC)

# 链接目标文件生成可执行文件
$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# 编译源文件生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(EXEC) $(OBJECTS)

# 伪目标，避免与同名文件冲突
.PHONY: all clean