DEBUG ?= 1
ifeq ($(DEBUG), 1)	
	FLAGS = -g -D DEBUG -o build/debug/main.exe
else
	FLAGS = -o build/release/main.exe
endif

default: 
	g++ src/*.cpp $(FLAGS) -O2 -Wall -Wextra -Werror -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm