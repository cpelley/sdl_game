#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<iostream>

#include<SDL2/SDL.h>


class GameObject{
    protected:
	std::string _texture_id;

	int _current_frame;
	int _current_row;

	int _x;
	int _y;

	int _width;
	int _height;

    public:
	void load(int x, int y, int width, int height, std::string texture_id);
        void draw(SDL_Renderer* renderer);
	void update();
	void clean();};

#endif
