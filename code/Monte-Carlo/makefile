define colorecho
      @tput setaf 6
      @echo $1
      @tput sgr0
endef

CC = g++
CCFLAGS = -larmadillo -lblas -llapack -std=c++11 -O3
DEPS = ./include/mclib.h
OBJ = ./obj/input-func.o ./obj/Monte-Carlo.o

NO_OF_FILES := $(words $(OBJ))
COUNTER = 1
GREEN=\x1b[32;01m
NO_COLOR=\x1b[0m

main: $(OBJ) $(DEPS)
	@$(CC) $(wildcard ./obj/*.o) main.cpp $(CCFLAGS) -o main.exe
	@if [ -f "main.exe" ]; then echo "Binary main.exe built \033[0;32msuccesfully\033[0m!"; fi

./obj/%.o: ./src/%.cpp obj_dir $(DEPS)
	@$(CC) $(CCFLAGS) $< -c; \
	mv *.o ./obj/
	@echo "$< compiled \t \t \033[0;32m$(COUNTER)/$(NO_OF_FILES)\033[0m"
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))

obj_dir:
	@if [ ! -d "./obj" ]; then echo "Making obj directory"; mkdir obj; fi

clean:
	@rm -rf obj main.exe