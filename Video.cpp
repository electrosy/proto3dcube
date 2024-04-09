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

    drawVertex(renderer, mModelPtr->cube().A());
    drawVertex(renderer, mModelPtr->cube().B());
    drawVertex(renderer, mModelPtr->cube().C());
    drawVertex(renderer, mModelPtr->cube().D());

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


    SDL_FPoint adjust = {mModelPtr->cube().x() + (mModelPtr->cube().width()/2), mModelPtr->cube().y() + (mModelPtr->cube().height()/2)};

    SDL_FPoint p1 = Transform::rotate(mModelPtr->cube().A(2).position, mModelPtr->getDegrees());
    drawVertex(renderer, {p1.x + adjust.x, p1.y + adjust.y, mModelPtr->cube().A(2).color});

    SDL_FPoint p2 = Transform::rotate(mModelPtr->cube().B(2).position, mModelPtr->getDegrees());
    drawVertex(renderer, {p2.x + adjust.x, p2.y + adjust.y, mModelPtr->cube().B(2).color});

    SDL_FPoint p3 = Transform::rotate(mModelPtr->cube().C(2).position, mModelPtr->getDegrees());
    drawVertex(renderer, {p3.x + adjust.x, p3.y + adjust.y, mModelPtr->cube().C(2).color});

    SDL_FPoint p4 = Transform::rotate(mModelPtr->cube().D(2).position, mModelPtr->getDegrees());
    drawVertex(renderer, {p4.x + adjust.x, p4.y + adjust.y, mModelPtr->cube().D(2).color});


    setDrawColor(renderer, mModelPtr->cube().A().color);
    SDL_RenderDrawLine(renderer, p1.x + adjust.x, p1.y + adjust.y,
                            p2.x + adjust.x, p2.y + adjust.y);

    setDrawColor(renderer, mModelPtr->cube().B().color);
    SDL_RenderDrawLine(renderer, p2.x + adjust.x, p2.y + adjust.y, 
                            p3.x + adjust.x, p3.y + adjust.y);

    setDrawColor(renderer, mModelPtr->cube().C().color);
    SDL_RenderDrawLine(renderer, p3.x + adjust.x, p3.y + adjust.y, 
                            p4.x + adjust.x, p4.y + adjust.y);

    setDrawColor(renderer, mModelPtr->cube().D().color);
    SDL_RenderDrawLine(renderer, p4.x + adjust.x, p4.y + adjust.y, 
                            p1.x + adjust.x, p1.y + adjust.y);                                                            
    



    //points
    float x_proj;
    float y_proj;
    for (int i = 0; i < 8; ++i) {
        // Divide the x and y coordinates by the z coordinate to 
        // project the point onto the canvas
        projectedPoints[i].x = x_proj = corners[i][0] / -corners[i][2] * 300 + mModelPtr->offset().x;
        projectedPoints[i].y = y_proj = corners[i][1] / -corners[i][2] * 300 + mModelPtr->offset().y;
        //SDL_Log("Projected corner %d: x:%f, y:%f\n", i, x_proj, y_proj);
        SDL_RenderDrawPointF(renderer, x_proj, y_proj);
    }

    
    SDL_RenderDrawLineF(renderer, projectedPoints[0].x, projectedPoints[0].y, projectedPoints[1].x, projectedPoints[1].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[0].x, projectedPoints[0].y, projectedPoints[2].x, projectedPoints[2].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[2].x, projectedPoints[2].y, projectedPoints[3].x, projectedPoints[3].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[1].x, projectedPoints[1].y, projectedPoints[3].x, projectedPoints[3].y);

    SDL_RenderDrawLineF(renderer, projectedPoints[4].x, projectedPoints[4].y, projectedPoints[5].x, projectedPoints[5].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[4].x, projectedPoints[4].y, projectedPoints[6].x, projectedPoints[6].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[6].x, projectedPoints[6].y, projectedPoints[7].x, projectedPoints[7].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[7].x, projectedPoints[7].y, projectedPoints[5].x, projectedPoints[5].y);

    SDL_RenderDrawLineF(renderer, projectedPoints[0].x, projectedPoints[0].y, projectedPoints[4].x, projectedPoints[4].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[1].x, projectedPoints[1].y, projectedPoints[5].x, projectedPoints[5].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[2].x, projectedPoints[2].y, projectedPoints[6].x, projectedPoints[6].y);
    SDL_RenderDrawLineF(renderer, projectedPoints[3].x, projectedPoints[3].y, projectedPoints[7].x, projectedPoints[7].y);
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