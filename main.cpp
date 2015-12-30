#include "game.h"
#include<SDL2/SDL.h>
#include<iostream>


Game* game = NULL;


int main(int argc, char* args[]) {
    game = new Game();
    bool sucessful;
    sucessful = game->init("Some title", 640, 480, false, true);
    if (sucessful != true){
        return 1;}

    while (game->running()) {
        game->handle_events();
        game->update();
        game->render();
	// add delay as simple way of setting fps
	SDL_Delay(10);
    } 
    game->clean();

    return 0;
}
