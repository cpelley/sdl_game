CXX = g++
COMPILER_FLAGS = -std=c++11 -w
LINKER_FLAGS = -lSDL2 -lSDL2_image #-lSDL2_ttf -lSDL2_mixer
OBJ_NAME = run
OBJS = main.o game.o texturemanager.o player.o enemy.o sdlgameobject.o

default: program
all: program clean

program: $(OBJS)
	$(CXX) $(COMPILER_FLAGS) -o $(OBJ_NAME) $^ $(LINKER_FLAGS)

main.o: main.cpp game.o
	$(CXX) -c $(COMPILER_FLAGS) $<

game.o: game.cpp texturemanager.o player.o enemy.o
	$(CXX) -c $(COMPILER_FLAGS) $<

texturemanager.o: texturemanager.cpp
	$(CXX) -c $(COMPILER_FLAGS) $<

sdlgameobject.o: sdlgameobject.cpp
	$(CXX) -c $(COMPILER_FLAGS) $<

player.o: player.cpp sdlgameobject.o
	$(CXX) -c $(COMPILER_FLAGS) $<

enemy.o: enemy.cpp sdlgameobject.o
	$(CXX) -c $(COMPILER_FLAGS) $<

.PHONY: clean cleanest

clean:
	-@rm *.o 2> /dev/null  || true

cleanest: clean
	-@rm $(OBJ_NAME) 2> /dev/null  || true

#http://www.cplusplus.com/forum/unices/12499/#msg59885
