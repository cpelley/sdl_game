#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>

#include "gameobject.h"


class Player : public GameObject{
    public:
	void load(int x, int y, int width, int height, std::string texture_id);
        void draw(SDL_Renderer* renderer);
	void update();
	void clean();};

#endif
