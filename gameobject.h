#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<iostream>

#include<SDL2/SDL.h>


class GameObject {
    protected:
	std::string _texture_id;

	int _current_frame;
	int _current_row;

	int _x;
	int _y;

	int _width;
	int _height;

    public:
        // virtual keyword to ensure that type determined at run-time - allows
	// us to use GameObject pointers for when referring to subclasses for
	// example.
	virtual void load(int x, int y, int width, int height, std::string texture_id);
        virtual void draw(SDL_Renderer* renderer);
	virtual void update();
	virtual void clean(){}
};

#endif
