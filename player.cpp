#include<SDL2/SDL.h>
#include "player.h"


Player::Player(const LoaderParams* params) : SDLGameObject(params) {}


void Player::draw() {
    SDLGameObject::draw();
}


void Player::update() {
    _x -= 1;
    _current_frame = int(((SDL_GetTicks() / 100) % 6));
}


void Player::clean(){}
