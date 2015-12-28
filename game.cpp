#include<iostream>
#include<vector>

#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>

#include "game.h"
#include "gameobject.h"
#include "enemy.h"
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

    TextureManager::get_instance()->load("resources/animate.png", "animate",
                                         _renderer);

    // Initialise game objects
    _player = new Player();
    _game_object = new GameObject();
    _enemy = new Enemy();

    // Populate vector with our game objects
    _game_objects.push_back(_player);
    _game_objects.push_back(_game_object);
    _game_objects.push_back(_enemy);

    _game_object->load(100, 100, 128, 82, "animate");
    _player->load(300, 300, 128, 82, "animate");
    _enemy->load(0, 0, 128, 82, "animate");

    _running = true;
    return true;}


void Game::render(){
    // Clear the window
    SDL_RenderClear(_renderer);

    for(std::vector<GameObject*>::size_type i = 0; i != _game_objects.size();
            i++){
        _game_objects[i]->draw(_renderer);}

    // Show window
    SDL_RenderPresent(_renderer);}


void Game::update(){
    for(std::vector<GameObject*>::size_type i = 0; i != _game_objects.size();
            i++){
        _game_objects[i]->update();}}


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
