#include<iostream>

#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>

#include "game.h"
#include "texture_manager.h"


bool Game::init(const char* title, int width, int height, bool fullscreen,
                bool centered, int xpos, int ypos){
    int flags = SDL_WINDOW_SHOWN;
    if (fullscreen == true){
        flags = SDL_WINDOW_FULLSCREEN;}

    if (centered == true){
        xpos = ypos = SDL_WINDOWPOS_CENTERED;}

    // Initialise SDL
    if (SDL_Init(SDL_INIT_VIDEO) >= 0){
        _window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);}
    else{
         std::cout << "SDL could not initialised.  SDL_Error: " <<
            SDL_GetError() << "\n";}

    // Initialise Renderer
    if (_window != NULL){
        _renderer = SDL_CreateRenderer(_window, -1, 0);}
    else{
         std::cout << "Renderer could not be initialised.  SDL_Error: " <<
            SDL_GetError() << "\n";}

    // Quit program as problem occured during SDL initialisation
    if (_renderer != NULL){
        // Set white background colour
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);}
    else{
        return false;}

    // Initialise multi format image loading from SDL image library
    int imgflags = IMG_INIT_PNG;
    if(!(IMG_Init(imgflags) & imgflags)) {
        std::cout << "SDL_image could not be initialised. " <<
            "SDL_image Error: " << IMG_GetError();
        return false;}

    _texture_manager.load("resources/animate.png", "animate", _renderer);

    _running = true;
    return true;}


void Game::render(){
    // Clear the window
    SDL_RenderClear(_renderer);

    _texture_manager.draw("animate", 0,0, 128, 82, _renderer);
    _texture_manager.draw_frame("animate", 100, 100, 128, 82, 1, _current_frame,
                               _renderer);

    // Show window
    SDL_RenderPresent(_renderer);}


void Game::update(){
    _current_frame = int((SDL_GetTicks() / 100) % 6);}


void Game::clean(){
    // Clean up SDL
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();}


void Game::handle_events(){
    SDL_Event event;
    if (SDL_PollEvent(&event)){
    switch(event.type){
            case SDL_QUIT:
                _running = false;
            break;

	        default:
	        break;}}}
