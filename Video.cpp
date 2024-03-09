#include <string>

#include "Video.h"
#include "Cube.h"
#include "Transform.h"

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

ley::Video::Video(ley::Model* model)
:
video_ready(true),
window(nullptr),
renderer(nullptr) {
    createWindow();
    createRenderer();

    mModelPtr = model;
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

void ley::Video::setDrawColor(SDL_Renderer* r, SDL_Color c) {
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
}


//draw 4 pixels for each vertex.
void ley::Video::drawVertex(SDL_Renderer* r, SDL_Vertex v) {
    setDrawColor(r, v.color);
    SDL_RenderDrawPoint(r, v.position.x, v.position.y);
    SDL_RenderDrawPoint(r, v.position.x+1, v.position.y);
    SDL_RenderDrawPoint(r, v.position.x, v.position.y+1);
    SDL_RenderDrawPoint(r, v.position.x+1, v.position.y+1);
}

void ley::Video::render() {

    //Cube cube1;

    drawVertex(renderer, mModelPtr->cube().A());
    drawVertex(renderer, mModelPtr->cube().B());
    drawVertex(renderer, mModelPtr->cube().C());
    drawVertex(renderer, mModelPtr->cube().D());

    //float xAdjust = - cube1.width() /2;
    //float yAdjust = - cube1.height() /2;


    setDrawColor(renderer, mModelPtr->cube().A().color);
    SDL_RenderDrawLine(renderer, mModelPtr->cube().A().position.x, mModelPtr->cube().A().position.y, 
                            mModelPtr->cube().B().position.x, mModelPtr->cube().B().position.y);

    setDrawColor(renderer, mModelPtr->cube().B().color);
    SDL_RenderDrawLine(renderer, mModelPtr->cube().B().position.x, mModelPtr->cube().B().position.y, 
                            mModelPtr->cube().C().position.x, mModelPtr->cube().C().position.y);

    setDrawColor(renderer, mModelPtr->cube().C().color);
    SDL_RenderDrawLine(renderer, mModelPtr->cube().C().position.x, mModelPtr->cube().C().position.y, 
                            mModelPtr->cube().D().position.x, mModelPtr->cube().D().position.y);

    setDrawColor(renderer, mModelPtr->cube().D().color);
    SDL_RenderDrawLine(renderer, mModelPtr->cube().D().position.x, mModelPtr->cube().D().position.y, 
                            mModelPtr->cube().A().position.x, mModelPtr->cube().A().position.y);                     

    
    
    
    // TODO this should be a static class.
    Transform transformation;

    SDL_FPoint p1 = transformation.rotate({mModelPtr->cube().A().position.x,mModelPtr->cube().A().position.y}, mModelPtr->getDegrees());
    drawVertex(renderer, {p1.x, p1.y, mModelPtr->cube().A().color});

    SDL_FPoint p2 = transformation.rotate({mModelPtr->cube().B().position.x,mModelPtr->cube().B().position.y}, mModelPtr->getDegrees());
    drawVertex(renderer, {p2.x, p2.y, mModelPtr->cube().B().color});

    SDL_FPoint p3 = transformation.rotate({mModelPtr->cube().C().position.x,mModelPtr->cube().C().position.y}, mModelPtr->getDegrees());
    drawVertex(renderer, {p3.x, p3.y, mModelPtr->cube().C().color});

    SDL_FPoint p4 = transformation.rotate({mModelPtr->cube().D().position.x,mModelPtr->cube().D().position.y}, mModelPtr->getDegrees());
    drawVertex(renderer, {p4.x, p4.y, mModelPtr->cube().D().color});


    setDrawColor(renderer, mModelPtr->cube().A().color);
    SDL_RenderDrawLine(renderer, p1.x, p1.y, 
                            p2.x, p2.y);

    setDrawColor(renderer, mModelPtr->cube().B().color);
    SDL_RenderDrawLine(renderer, p2.x, p2.y, 
                            p3.x, p3.y);

    setDrawColor(renderer, mModelPtr->cube().C().color);
    SDL_RenderDrawLine(renderer, p3.x, p3.y, 
                            p4.x, p4.y);

    setDrawColor(renderer, mModelPtr->cube().D().color);
    SDL_RenderDrawLine(renderer, p4.x, p4.y, 
                            p1.x, p1.y);                                                            
    
}

void ley::Video::present() {

    if(video_ready) {
        SDL_RenderPresent(renderer);
    }
}

void ley::Video::clear() {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
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