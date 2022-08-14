default: 
	g++ src/*.cpp -o build/main.exe -O2 -Wall -Wextra -Werror -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm