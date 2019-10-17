CC = g++
CCFLAGS =  -std=c++11 -O3 #-larmadillo -lblas -llapack

main: obj
	$(CC) $(wildcard *.o) examplefunction.cpp $(CCFLAGS) -o examplefunction.exe

obj:
	$(CC) $(CCFLAGS) $(wildcard funcs/*.cpp) -c

clean:
	rm -rf *.o main.exe
