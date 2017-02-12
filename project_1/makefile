EXE = project1
SOURCE := src/project_1.c src/data.c src/memory.c
OBJECT := $(SOURCE: .c=.o)
INCLUDE = inc/
CFLAGS = -std=c99 -Wall -O0
LDFLAGS = -Xlinker -Map=$(EXE).map

PLATFORM = 
ARCH := $(shell arch)
OS := $(shell uname -s)

ifeq ($(OS), Linux)
ifeq ($(PLATFORM), host)
CC = gcc
else ifeq ($(PLATFORM), bbb)
CC = arm-linux-gnueabi-gcc
endif
else
CC = arm-none-eabi-gcc
endif


$(EXE):	$(OBJECT)
	$(CC) -I$(INCLUDE) $(OBJECT) -o $(EXE) $(CFLAGS) $(LDFLAGS)
