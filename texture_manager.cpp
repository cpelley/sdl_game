#include<iostream>

#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>

#include "texture_manager.h"


TextureManager* TextureManager::_instance = NULL;


bool TextureManager::load(std::string filename, std::string id,
                          SDL_Renderer* renderer) {
    // Initialise textures
    SDL_Surface* tmp_surface = IMG_Load(filename.c_str());
    if(tmp_surface == NULL) {
        std::cout << "Unable to load image " << filename.c_str() <<
            " SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    if(texture == NULL) {
        std::cout << "Unable to create texture from " << filename.c_str() <<
            " SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    else {
        _texture_map[id] = texture;
    }
    return true;
}


void TextureManager::draw(std::string id, int x, int y, int width, int height,
                          SDL_Renderer* renderer, SDL_RendererFlip flip) {
    SDL_Rect source_rectangle;
    SDL_Rect target_rectangle;

    // Get width and height of texture
    //SDL_QueryTexture(_texture_map[id], NULL, NULL, &_source_rectangle.w,
    //                 &_source_rectangle.h);
    target_rectangle.x = x; source_rectangle.x = 0;
    target_rectangle.y = x; source_rectangle.y = 0;
    target_rectangle.w = source_rectangle.w = width;
    target_rectangle.h = source_rectangle.h = height;

    SDL_RenderCopyEx(renderer, _texture_map[id], &source_rectangle,
                     &target_rectangle, 0, 0, flip);
}


void TextureManager::draw_frame(std::string id, int x, int y, int width,
                                int height, int current_row, int current_frame,
                                SDL_Renderer* renderer,
				SDL_RendererFlip flip) {
    SDL_Rect source_rectangle;
    SDL_Rect target_rectangle;
    source_rectangle.x = width * current_frame;
    source_rectangle.y = height * (current_row - 1);
    source_rectangle.w = target_rectangle.w = width;
    source_rectangle.h = target_rectangle.h = height;
    target_rectangle.x = x;
    target_rectangle.y = y;
    SDL_RenderCopyEx(renderer, _texture_map[id], &source_rectangle,
                     &target_rectangle, 0, 0, flip);
}
