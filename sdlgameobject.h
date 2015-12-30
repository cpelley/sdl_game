#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H
#include<iostream>

#include "gameobject.h"
#include "loaderparams.h"


class SDLGameObject : public GameObject {
    protected:
        int _x;
        int _y;
        int _width;
        int _height;
        std::string _texture_id;
        int _current_row;
        int _current_frame;

    public:
        SDLGameObject(const LoaderParams* params);
        virtual void draw();
	    virtual void update() = 0;
	    virtual void clean() = 0;
};

#endif
