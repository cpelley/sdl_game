#ifndef PLAYER_H
#define PLAYER_H

#include "sdlgameobject.h"
#include "loaderparams.h"


class Player : public SDLGameObject {
    public:
        Player(const LoaderParams* params);
        virtual void draw();
	    virtual void update();
	    virtual void clean();
};

#endif
