
# Comment lines
# General makefile for c++ - choose PROG =   name of given program
# Here we define compiler option, libraries and the  target
CPPflags= g++ -O3
# Here we define the library functions we nee
LIB = #-larmadillo -llapack -lblas
# Here we define the name of the executable
PROG= test.exe
${PROG} :	   	test_main.o  test_func.o examplefunction.o
		${CPPflags} test_main.o test_func.o examplefunction.o ${LIB} -o ${PROG}

test_main.o :			test_main.cpp
						${CPPflags} -c test_main.cpp

test_func.o :			test_func.cpp
						${CPPflags} -c test_func.cpp

examplefunction.o :		../../Programcode/examplefunction.cpp
						${CPPflags} -c ../../Programcode/examplefunction.cpp


clean:
						rm -rf *.o test.exe
