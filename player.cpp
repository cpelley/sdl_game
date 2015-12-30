#include "gameobject.h"
#include "player.h"


void Player::load(int x, int y, int width, int height, std::string texture_id) {
    GameObject::load(x, y, width, height, texture_id);
}


void Player::draw(SDL_Renderer* renderer) {
    GameObject::draw(renderer);
}


void Player::update() {
    _x -= 1;
}
