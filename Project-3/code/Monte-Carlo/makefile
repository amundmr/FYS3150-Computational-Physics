CC = g++
CCFLAGS = -larmadillo -lblas -llapack -std=c++11   -fopenmp -O3
DEPS = ./include/mclib.h
OBJ = ./obj/input-func.o ./obj/naiveMC.o ./obj/input-func_sphere.o ./obj/improvedMC.o

NO_OF_FILES := $(words $(OBJ))
COUNTER = 1

main: $(OBJ) $(DEPS)
	@$(CC) $(wildcard ./obj/*.o) main.cpp $(CCFLAGS) -o main.exe
	@if [ -f "main.exe" ]; then echo "Binary main.exe built \033[0;32msuccessfully\033[0m!"; fi

./obj/%.o: ./src/%.cpp obj_dir $(DEPS)
	@$(CC) $(CCFLAGS) $< -c; \
	mv *.o ./obj/
	@echo "$< compiled\t\t\t \033[0;32m$(COUNTER)/$(NO_OF_FILES)\033[0m"
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))

obj_dir:
	@if [ ! -d "./obj" ]; then echo "Making \033[0;36mobj\033[0m directory"; mkdir obj; fi

clean:
	@rm -rf obj main.exe
	@echo "Directory \033[0;36mobj\033[0m and executable \033[0;36mmain.exe\033[0m deleted."
