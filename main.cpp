#include "game.h"
#include<SDL2/SDL.h>
#include<iostream>


Game* game = NULL;


int main(int argc, char* args[]){
    game = new Game();
    bool sucessful;
    sucessful = game->init("Some title", 0, 0, 640, 480, 0);

    while (game->running()){
        game->handle_events();
        game->update();
        game->render();}
    game->clean();

    return 0;}
