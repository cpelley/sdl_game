#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "loaderparams.h"


class GameObject {
    protected:
        GameObject(const LoaderParams* params) {}
	virtual ~GameObject() {}

    public:
    // virtual keyword to ensure that type determined at run-time - allows
	// us to use GameObject pointers for when referring to subclasses for
	// example.  Here we turn these into pure virtual functions by setting to
	// zero.  Pure virtual functions then make this an abstract class.
    virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
};

#endif
