#include "game.h"
#include<SDL2/SDL.h>


engine::Game* ame = 0;


int main(int argc, char* args[]){
    ame = new engine::Game();
    bool hello;
    hello = ame->init("Some title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
            SDL_WINDOW_SHOWN);

    while (ame->running()){
        //ame->handle_events();
        ame->update();
        ame->render();}
    ame->clean();

    return 0;}
