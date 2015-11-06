#include<iostream>
#include<SDL2/SDL.h>


SDL_Window* WINDOW = NULL;
SDL_Renderer* RENDERER = NULL;


bool RUNNING = false;


bool init(const char* title, int xpos, int ypos, int height, int width, int flags){
    // Initialise SDL
    if (SDL_Init(SDL_INIT_VIDEO) >= 0){
        WINDOW = SDL_CreateWindow(title, xpos, ypos, height, width, flags);}
    else{
         std::cout << "SDL could not initialised.  SDL_Error: " <<
            SDL_GetError() << std::endl;}

    // Initialise Renderer
    if (WINDOW != NULL){
        RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED);}
    else{
         std::cout << "Renderer could not be initialised.  SDL_Error: " <<
            SDL_GetError() << std::endl;}

    // Quit program as problem occured during SDL initialisation
    if (RENDERER == NULL){
        return false;}
    return true;}


void render(){
    // Set black background
    SDL_SetRenderDrawColor(RENDERER, 0, 0, 0, 255);

    // Draw the window
    SDL_RenderClear(RENDERER);

    // Show window
    SDL_RenderPresent(RENDERER);}


int main(int argc, char* args[]){
    if (init("Some title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             640, 480, SDL_WINDOW_SHOWN)){
        RUNNING = true;}
    else{
        return 1;}

    while (RUNNING){
        render();}

    // Clean up SDL
    SDL_Quit();

    return 0;
}
