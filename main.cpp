#include<iostream>
#include<SDL2/SDL.h>


SDL_Window* WINDOW = NULL;
SDL_Renderer* RENDERER = NULL;


int main(int argc, char* args[]){
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        WINDOW = SDL_CreateWindow("Some title", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, 640, 480,
                                  SDL_WINDOW_SHOWN);}
    else{
         std::cout << "SDL could not initialised.  SDL_Error: " <<
            SDL_GetError() << std::endl;}

    // Initialise Renderer
    if (WINDOW != NULL){
        RENDERER = SDL_CreateRenderer(WINDOW, -1, 0);}
    else{
         std::cout << "Renderer could not be initialised.  SDL_Error: " <<
            SDL_GetError() << std::endl;}

    // Quit program as problem occured during SDL initialisation
    if (RENDERER == NULL){
        return 1;}

    // Set black background
    SDL_SetRenderDrawColor(RENDERER, 0, 0, 0, 255);

    // Draw the window
    SDL_RenderClear(RENDERER);

    // Show window
    SDL_RenderPresent(RENDERER);

    // Set delay
    SDL_Delay(5000);

    // Clean up SDL
    SDL_Quit();

    return 0;
}
