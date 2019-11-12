CC = g++

# Flags for compiler.
CCFLAGS = -larmadillo -lblas -llapack -std=c++11 #-fopenmp -O3

# Names of files in src you want to compile: "./obj/<name>.o".
OBJ = ./obj/initialize.o ./obj/input.o ./obj/output.o  ./obj/metropolis.o ./obj/periodic_boundary_conditions.o ./obj/initialize_random.o

# Headerfile(s) used.
DEPS = ./include/lib.h

#------------------------------------
# No need to change the stuff below.
NO_OF_FILES := $(words $(OBJ))
COUNTER = 1

main: $(OBJ) $(DEPS)
	@$(CC) $(wildcard ./obj/*.o) main.cpp $(CCFLAGS) -o main.exe
	@if [ -f "main.exe" ]; then echo "Binary main.exe built \033[0;32msuccessfully\033[0m!"; fi

./obj/%.o: ./src/%.cpp obj_dir $(DEPS)
	@$(CC) $(CCFLAGS) $< -c; \
	mv *.o ./obj/
	@printf "%-50s \033[0;32m$(COUNTER)/$(NO_OF_FILES)\033[0m\n" "$< compiled"
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))

obj_dir:
	@if [ ! -d "./obj" ]; then echo "Making \033[0;36mobj\033[0m directory"; mkdir obj; fi

clean:
	@rm -rf obj main.exe
	@echo "Directory \033[0;36mobj\033[0m and executable \033[0;36mmain.exe\033[0m deleted."
