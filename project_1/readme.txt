Makefile consists of many environment variables:

-------------------------In source.mk file-----------------------------------
EXE = name of the output executable/target
SOURCE := source C files, present in .src directory
OBJECT := object file created after compile and will be saved in libraries/
INCLUDE = the directory for the header files
-----------------------------------------------------------------------------


--------------------------In makefile----------------------------------------
CFLAGS -- which are compiler flags
LDFLAGS -- linker flags that generate map file.
PLATFORM_FLAG -- which defines the platform on which code will be run

PLATFORM -- the platform such as arm/native (can be given with inline command)
ARCH: architecture of the host machine (can be given with inline command)
OS: Linux/Other

CC -- that defines the compiler to be used.
      if OS is Linux and platform is host, use gcc
      if OS is linux and platform is bbb, use arm-linux-gnueabi-gcc
      else use arm-none-eabi-gcc


TARGETS:
	compile_all: it will compile all the source files in src directory
		     and save the object files in newly created libraries/
		     dependencies are only src files

	build: it depends on the compiled file and the *.dep file target
	        it takes all the object file and build a executable file 
		named project1.out

	build_lib: it depends on the compile_all target and it creates a 
		   libraries.archive directoy where it saves the archived 
		   object files created as libproject1.a

	$(EXE).dep: it will create a dependenies files 

	%.i:  it depends on the src/%.c files. make takes command line 
	      argument as make xyz.i and it creates a preprocessor o/p file
	      using the src/xyz.c files
	
	%.asm: it depends on the src/%.c files. make takes command line 
	      argument as make xyz.asm and it creates an assembly o/p file
	      using the src/xyz.c files

	%.s:	it depends on the src/%.c files. make takes command line 
	      argument as make xyz.s and it creates a assembly o/p file
	      using the src/xyz.c files

	%.o:	it depends on the src/%.c files. make takes command line 
	      argument as make xyz.o and it creates an object o/p file
	      using the src/xyz.c files


#to remove all the generated files.
clean: 
	rm -rf *.map *.out *.o *~ libraries *.i *.asm *.s *.dep

#To give phony protection to all the targets
.Phony: clean build_lib compile_all

------------------------------------------------------------------------------------
