#pragma once

#include <SDL2/SDL.h>

namespace ley {

class Video {

private:

    Uint32 frame_start;
    bool video_ready = false;
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Video();
    ~Video();

    void createRenderer();
    void createWindow();
    void render();
    void present();
    void clear();
    void frameStart();
    void frameDelay();

};

}