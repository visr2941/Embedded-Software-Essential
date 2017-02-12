include sources.mk

CFLAGS = -std=c99 -Wall -O0
LDFLAGS = -Xlinker -Map=$(EXE).map

PLATFORM = host
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

libraries:
	mkdir libraries/
	$(CC) -c $(SOURCE) -I$(INCLUDE)
	mv *.o libraries/

$(EXE): libraries
	$(CC) src/project_1.c -I$(INCLUDE) $(OBJECT) -o $(EXE) $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.map *.out *.o *~ libraries
