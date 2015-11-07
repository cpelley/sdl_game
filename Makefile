CC = g++
COMPILER_FLAGS = -std=c++11 -w
LINKER_FLAGS = -lSDL2 -lSDL2_image #-lSDL2_ttf -lSDL2_mixer
OBJ_NAME = run

default: program
all: program clean

program: main.o
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_NAME) $^ $(LINKER_FLAGS)

main.o: main.cpp game.h
	$(CC) -c $(COMPILER_FLAGS) $<

game.o: game.cpp game.h
	$(CC) -c $(COMPILER_FLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm $(OBJ_NAME)


#http://www.cplusplus.com/forum/unices/12499/
