#include<iostream>

#include "game.h"
#include<SDL2/SDL.h>


const int FPS = 60;


const int DELAY_TIME = 1.e3/FPS;


int main(int argc, char* args[]) {
    Uint32 frame_time = 0, frame_start;

    std::cout << "Initialising game...\n";
    if (Game::get_instance()->init("Some title", 640, 480, false, true)) {
        std::cout << "Game initialisation successful\n";

        while (Game::get_instance()->running()) {
            frame_start = SDL_GetTicks();

            Game::get_instance()->handle_events();
            Game::get_instance()->update();
            Game::get_instance()->render();

        	// add delay as simple way of capping frames-per-second
            frame_time = SDL_GetTicks() - frame_start;
            if (frame_time < DELAY_TIME) {
                SDL_Delay((int) (DELAY_TIME - frame_time));
            }
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
