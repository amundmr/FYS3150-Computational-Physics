CC = g++
CFLAGS = -std=c++11 -larmadillo -llapack -lblas

main: obj
	$(CC) $(wildcard *.o) bisection.cpp $(CCFLAGS) -o bisection.exe

obj:
	$(CC) $(CCFLAGS) ../Jacobi_method/Jacobi_method.cpp ../Jacobi_method/Jacobi_rotate.cpp ../Jacobi_method/off.cpp -c

clean:
	rm -rf *.o bisection.exe
