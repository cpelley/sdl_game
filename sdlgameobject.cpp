#include "game.h"
#include "sdlgameobject.h"
#include "loaderparams.h"
#include "texturemanager.h"


SDLGameObject::SDLGameObject(const LoaderParams* params) :
        GameObject(params) {
    _x = params->get_x();
    _y = params->get_y();
    _width = params->get_width();
    _height = params->get_height();
    _texture_id = params->get_texture_id();
    _current_row = 1;
    _current_frame = 1;
}


void SDLGameObject::draw() {
    TextureManager::get_instance()->draw_frame(_texture_id, _x, _y, _width,
                                               _height, _current_row,
                                               _current_frame,
                                               Game::get_instance()->get_renderer());
}
