include sources.mk

CFLAGS = -std=c99 -Wall -g -O0 -Werror $(PLATFORM_FLAG)=$(ARCH)
LDFLAGS = -Xlinker -Map=$(EXE).map
PLATFORM_FLAG = -march

PLATFORM = host
ARCH = native
OS := $(shell uname -s)
MACRO = abc 

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
	$(CC) -D$(MACRO) -c $(SOURCE) $(INCLUDE)
	mv *.o libraries/

build: compile_all $(EXE).dep
	$(CC) -D$(MACRO) $(INCLUDE) $(OBJECT) -o $(EXE).out $(CFLAGS) $(LDFLAGS)

build_lib: compile_all
	if [ ! -e ./libraries/archive ]; then mkdir libraries/archive; fi
	ar cr ./libraries/archive/libproject1.a libraries/data.o libraries/memory.o

$(EXE).dep: $(SOURCE)
	$(CC) $^ $(INCLUDE) $(CFLAGS) -M -o $@

%.i: src/%.c
	$(CC) -E $< $(INCLUDE) -o $@

%.asm: src/%.c
	$(CC) -S $< $(INCLUDE) -o $@

%.s: src/%.c
	$(CC) -S $< $(INCLUDE) -o $@
	 
%.o: src/%.c
	$(CC) -c $< $(INCLUDE) -o $@

.PHONY: clean build_lib compile_all

clean:
	rm -rf *.map *.out *.o *~ libraries *.i *.asm *.s *.dep
