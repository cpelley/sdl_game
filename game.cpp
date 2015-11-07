#include<iostream>
#include "game.h"


namespace engine{

    bool Game::init(const char* title, int xpos, int ypos, int width, int height,
    		int flags){
        // Initialise SDL
        if (SDL_Init(SDL_INIT_VIDEO) >= 0){
            _window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);}
        else{
             std::cout << "SDL could not initialised.  SDL_Error: " <<
                SDL_GetError() << "\n";}
    
        // Initialise Renderer
        if (_window != NULL){
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);}
        else{
             std::cout << "Renderer could not be initialised.  SDL_Error: " <<
                SDL_GetError() << "\n";}
    
        // Quit program as problem occured during SDL initialisation
        if (_renderer != NULL){
            // Set white background colour
            SDL_SetRenderDrawColor(RENDERER, 255, 255, 255, 255);}
        else{
            return false;}
    
        _running = true;
        return true;}
    
    
    void Game::render(){
        // Clear the window
        SDL_RenderClear(_renderer);
    
        // Show window
        SDL_RenderPresent(_renderer);}
    
    
    void Game:clean(){
        // Clean up SDL
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);
        SDL_Quit();}
    
    
    void Game::handle_events(){
        SDL_Event event;
        if (SDL_PollEvent(&event)){
    	case SDL_QUIT:
    	    _running = False;
    	break;
    
    	default:
    	break;}}

}
