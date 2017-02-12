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

compile_all: $(SOURCE)
	if [ ! -e ./libraries/ ]; then mkdir libraries; fi
	$(CC) -c $(SOURCE) -I$(INCLUDE)
	mv *.o libraries/

%.i: src/%.c
	$(CC) -E $< $(INCLUDE) -o $@

%.asm: src/%.c
	$(CC) -S $< $(INCLUDE) -o $@

%.s: src/%.c
	$(CC) -S $< $(INCLUDE) -o $@
	 
%.o: src/%.c
	$(CC) -c $< $(INCLUDE) -o $@

build: compile_all
	$(CC) $(INCLUDE) $(OBJECT) -o $(EXE).out $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.map *.out *.o *~ libraries *.i *.asm *.s
