CC = g++
CCFLAGS = -larmadillo -lblas -llapack -std=c++11 -O3
DEPS = ./include/mclib.h

main: obj
	$(CC) $(wildcard ./obj/*.o) main.cpp $(CCFLAGS) -o main.exe

obj:
	$(CC) $(CCFLAGS) $(wildcard ./src/*.cpp) -c

clean:
	rm -rf *.o main.exe