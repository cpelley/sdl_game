#ifndef ENEMY_H
#define ENEMY_H

#include "sdlgameobject.h"
#include "loaderparams.h"


class Enemy : public SDLGameObject {
    public:
        Enemy(const LoaderParams* params);
        virtual void draw();
	    virtual void update();
	    virtual void clean();
};

#endif
