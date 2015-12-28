#ifndef GAME_H
#define GAME_H
#include<SDL2/SDL.h>


class Game{
    private:
        bool _running = false;
        SDL_Window* _window = NULL;
        SDL_Renderer* _renderer = NULL;

        int _current_frame;
        
    public:
        Game(){};
        ~Game(){};

        bool init(const char* title, int width, int height,
                  bool fullscreen=false, bool centered=false,
                  int xpos=0, int ypos=0);
        void render();
        void update();
        void handle_events();
        void clean();
        bool running(){return _running;}
};
#endif
