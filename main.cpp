#include<iostream>

#include "game.h"
#include<SDL2/SDL.h>


int main(int argc, char* args[]) {
    std::cout << "Initialising game...\n";
    if (Game::get_instance()->init("Some title", 640, 480, false, true)) {
        std::cout << "Game initialisation successful\n";

        while (Game::get_instance()->running()) {
            Game::get_instance()->handle_events();
            Game::get_instance()->update();
            Game::get_instance()->render();

        	// add delay as simple way of setting fps
        	SDL_Delay(10);
        }
    }
    else {
        std::cout << "Game initialisation failure.  SDL_ERROR: " << SDL_GetError() << "\n";
        return -1;
    }

    std::cout << "Closing Game\n";
    Game::get_instance()->clean();

    return 0;
}
