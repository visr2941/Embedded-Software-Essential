EXE = project2
SOURCE := src/main.c src/cirbuf.c
OBJECT := libraries/cirbuf.o libraries/main.o
INCLUDE = -Iinc/

CFLAGS = -std=c99 -Wall

PLATFORM = host
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
	$(CC) -c $(SOURCE) $(INCLUDE)
	mv *.o libraries/

build: compile_all $(EXE).dep
	$(CC) $(INCLUDE) $(OBJECT) -o $(EXE).out $(CFLAGS)


#build_lib: compile_all
#	if [ ! -e ./libraries/archive ]; then mkdir libraries/archive; fi
#	ar cr ./libraries/archive/libproject1.a libraries/data.o libraries/memory.o

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
