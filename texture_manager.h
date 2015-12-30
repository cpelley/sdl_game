#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include<SDL2/SDL.h>


#include <map>


class TextureManager {
    private:
        static TextureManager* _instance;
        std::map<std::string, SDL_Texture*> _texture_map;
        TextureManager(){};

    public:
        // Make the class a singleton
        static TextureManager* get_instance() {
            if(_instance == NULL){
                _instance = new TextureManager();}
            return _instance;
	    }

        ~TextureManager(){};

        bool load(std::string filename, std::string id,
                  SDL_Renderer* renderer);

        void draw(std::string id, int x, int y, int width, int height,
                  SDL_Renderer* renderer, SDL_RendererFlip flip=SDL_FLIP_NONE);

        void draw_frame(std::string id, int x, int y, int width,
                        int height, int current_row, int current_frame,
                        SDL_Renderer* renderer,
			            SDL_RendererFlip flip=SDL_FLIP_NONE);
};
#endif
