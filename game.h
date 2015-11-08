#ifndef GAME_H
#define GAME_H
#include<SDL2/SDL.h>


class Game{
    private:
        bool _running = false;
        SDL_Window* _window = NULL;
        SDL_Renderer* _renderer = NULL;

    public:
        Game(){};
        ~Game(){};

        bool init(const char* title, int xpos, int ypos, int width, int height,
    	      int flags);
        void render();
        void update(){}
        void handle_events();
        void clean();
        bool running(){return _running;}
};
#endif
