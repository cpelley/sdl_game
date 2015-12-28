#include "texture_manager.h"
#include "gameobject.h"


void GameObject::load(int x, int y, int width, int height,
		      std::string texture_id){
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _texture_id = texture_id;

    _current_row = _current_frame = 1;}


void GameObject::draw(SDL_Renderer* renderer){
    TextureManager::get_instance()->draw_frame(_texture_id, _x, _y, _width,
		    			       _height, _current_row,
					       _current_frame, renderer);}


void GameObject::update(){
    _x += 1;}
