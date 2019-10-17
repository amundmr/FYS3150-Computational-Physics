
# Comment lines
# General makefile for c++ - choose PROG =   name of given program
# Here we define compiler option, libraries and the  target
CPPflags= g++ -O3
# Here we define the library functions we nee
LIB = #-larmadillo -llapack -lblas
# Here we define the name of the executable
PROG= test.exe
${PROG} :	   	test_main.o  test_func.o gauleg.o int_function.o
		${CPPflags} test_main.o test_func.o gauleg.o int_function.o ${LIB} -o ${PROG}

test_main.o :			test_main.cpp
						${CPPflags} -c test_main.cpp

test_func.o :			test_func.cpp
						${CPPflags} -c test_func.cpp

gauleg.o :		../../Programcode/funcs/gauleg.cpp
						${CPPflags} -c ../../Programcode/funcs/gauleg.cpp

int_function.o :		../../Programcode/funcs/int_function.cpp
						${CPPflags} -c ../../Programcode/funcs/int_function.cpp


clean:
						rm -rf *.o test.exe
