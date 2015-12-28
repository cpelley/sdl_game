CXX = g++
COMPILER_FLAGS = -std=c++11 -w
LINKER_FLAGS = -lSDL2 -lSDL2_image #-lSDL2_ttf -lSDL2_mixer
OBJ_NAME = run

default: program
all: program clean

program: main.o game.o texture_manager.o gameobject.o player.o
	$(CXX) $(COMPILER_FLAGS) -o $(OBJ_NAME) $^ $(LINKER_FLAGS)

main.o: main.cpp game.o
	$(CXX) -c $(COMPILER_FLAGS) $<

game.o: game.cpp texture_manager.o gameobject.o player.o
	$(CXX) -c $(COMPILER_FLAGS) $<

texture_manager.o: texture_manager.cpp
	$(CXX) -c $(COMPILER_FLAGS) $<

gameobject.o: gameobject.cpp texture_manager.o
	$(CXX) -c $(COMPILER_FLAGS) $<

player.o: player.cpp gameobject.o
	$(CXX) -c $(COMPILER_FLAGS) $<

.PHONY: clean cleanest

clean:
	-@rm *.o 2> /dev/null  || true

cleanest: clean
	-@rm $(OBJ_NAME) 2> /dev/null  || true

#http://www.cplusplus.com/forum/unices/12499/
