#include<SDL2/SDL.h>
#include "enemy.h"


Enemy::Enemy(const LoaderParams* params) : SDLGameObject(params) {}


void Enemy::draw() {
    SDLGameObject::draw();
}


void Enemy::update() {
    _x += 1;
    _y += 1;
    _current_frame = int(((SDL_GetTicks() / 100) % 6));
}


void Enemy::clean(){}
