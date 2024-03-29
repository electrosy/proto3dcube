#pragma once

#include <SDL2/SDL.h>
#include "Model.h"

namespace ley {

class Video {

private:

    Uint32 frame_start;
    bool video_ready = false;
    SDL_Window* window;
    SDL_Renderer* renderer;
    ley::Model* mModelPtr;

public:
    Video(ley::Model* model);
    ~Video();

    void createRenderer();
    void createWindow();
    void render();
    void present();
    void clear();
    void frameStart();
    void frameDelay();
    void drawVertex(SDL_Renderer* r, SDL_Vertex v);

    void setDrawColor(SDL_Renderer*, SDL_Color c);

};

}