#把所有的目录设置成变量，方便修改和移植
CC = gcc
CFLAGS = -g -Wall -fPIC

G711 = ./G711
INCLUDE = ./include
G711SRC = ./G711
G729ARMSRC = ./G729A_ARM
G729PCSRC = ./G729A_PC

#将所有.c/.h文件列出来，并提取所有中间文件(.o)
SOURCE = $(wildcard ${G711}/*.c \
	${G711SRC}/*.c \
	${G729ARMSRC}/*.c \
	${G729PCSRC}/*.c \
	)

INCLUDE_DIRS = -I${INCLUDE}

OBJECT = $(patsubst %.c,%.o,$(SOURCE))

#设置最终目标文件
TARGET = p--mediacodecs.so
all : $(TARGET)

#用所有中间文件生成目标文件
$(TARGET) : $(OBJECT)
    g++ -rdynamic -shared -fPIC -o $@ $^

#生成各个中间文件
$(OBJECT) : %.o : %.c
    $(CC) -c $(CFLAGS) $< -o $@ $(INCLUDE_DIRS)

.PHONY : clean
clean :
    rm -rf $(TARGET) $(OBJECT)