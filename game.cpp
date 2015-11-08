#include<iostream>

#include<SDL2/SDL.h>

#include "game.h"


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

    // Initialise textures
    SDL_Surface* tmp_surface = SDL_LoadBMP("resources/rider.bmp");
    _texture = SDL_CreateTextureFromSurface(_renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);

    SDL_QueryTexture(_texture, NULL, NULL, &_source_rectangle.w, &_source_rectangle.h);
    _target_rectangle.x = _source_rectangle.x = 0;
    _target_rectangle.y = _source_rectangle.y = 0;
    _target_rectangle.w = _source_rectangle.w;
    _target_rectangle.h = _source_rectangle.h;

    _running = true;
    return true;}


void Game::render(){
    // Clear the window
    SDL_RenderClear(_renderer);

    SDL_RenderCopy(_renderer, _texture, &_source_rectangle, &_target_rectangle);

    // Show window
    SDL_RenderPresent(_renderer);}


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
