#include "gameobject.h"
#include "enemy.h"

#include<SDL2/SDL.h>


void Enemy::load(int x, int y, int width, int height, std::string texture_id){
    GameObject::load(x, y, width, height, texture_id);}


void Enemy::draw(SDL_Renderer* renderer){
    GameObject::draw(renderer);}


void Enemy::update(){
    _x += 1;
    _y += 1;
    _current_frame = int(((SDL_GetTicks() / 100) % 6));}
