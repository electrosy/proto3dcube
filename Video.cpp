#include <string>

#include "Video.h"

const auto TARGET_FPS = 144;
const auto DELAY_TIME = 1000.0f / TARGET_FPS;

const auto SCREEN_WIDTH = 1280;
const auto SCREEN_HEIGHT = 720;

const std::string APPLICATION_NAME = "proto3dcube";
const std::string APPLICATION_VER = "0.0.1.1"; //Major, Minor(Set of new features), Features, Bugfix or Refactor
const std::string APPLICATION_PLATFORM = SDL_GetPlatform();
const std::string APPLICATION_REL_TYPE = "Alpha";
const std::string APPLICATION_ENV = "Development";
const std::string SDL_VERSION_COMP_LABEL = "SDL Compiled Version: ";
const std::string SDL_VERSION_LINK_LABEL = "SDL Linked Version: ";

const std::string APPLICATION_STRING = APPLICATION_NAME + " " + APPLICATION_VER + " " +  APPLICATION_PLATFORM + " " +  APPLICATION_REL_TYPE + " " + APPLICATION_ENV;

ley::Video::Video()
:
video_ready(true),
window(nullptr),
renderer(nullptr) {
    createWindow();
    createRenderer();
}

ley::Video::~Video() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
}

void ley::Video::createWindow() {

    /* create a window to render to */
    if(SDL_InitSubSystem(SDL_INIT_VIDEO) >= 0) {
        // if all good
        window = SDL_CreateWindow(
            APPLICATION_STRING.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN /*SDL_WINDOW_FULLSCREEN*/);
    } else {
        printf("Can't Initialize SDL2 Video");
        video_ready = 0;
    }
}

void ley::Video::createRenderer() {
    /* create a renderer */
    if(window != nullptr) { 
        renderer = SDL_CreateRenderer(window, -1, 0 /*SDL_RENDERER_PRESENTVSYNC*/);
    } else {
        printf("Can't Initialize Renderer");
        video_ready = false;
    }
 
}

void ley::Video::present() {

    if(video_ready) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
    }
}

void ley::Video::clear() {
    SDL_RenderClear(renderer);
}

void ley::Video::frameStart() {
    frame_start = SDL_GetTicks();
}

void ley::Video::frameDelay() {
    Uint32 frame_time = SDL_GetTicks() - frame_start;

    if(frame_time < DELAY_TIME) {
        SDL_Delay((int)DELAY_TIME - frame_time);
    }
}