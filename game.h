#ifndef GAME_H
#define GAME_H
#include<vector>

#include<SDL2/SDL.h>

#include "gameobject.h"


class Game {
    private:
        Game(){};
        static Game* _instance;
        bool _running = false;
        SDL_Window* _window = NULL;
        SDL_Renderer* _renderer = NULL;

	    std::vector<GameObject*> _game_objects;
        
    public:
        // Make the class a singleton
        static Game* get_instance() {
            if(_instance == NULL){
                _instance = new Game();}
            return _instance;
	    }
        ~Game(){};

        bool init(const char* title, int width, int height,
                  bool fullscreen=false, bool centered=false,
                  int xpos=0, int ypos=0);
        void render();
        void update();
        void handle_events();
        void clean();
        bool running() {return _running;}

        SDL_Renderer* get_renderer() const {return _renderer;}
};
#endif
