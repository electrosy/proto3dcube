#include <iostream>

#include "Input.h"
#include "Video.h"
#include "Model.h"
#include "./inc/Vec3.h"




int main() {
    bool programRunning = true;

    ley::Model mModel;
    ley::Video mVideoSystem(&mModel);
    ley::Input mInputSystem;
    ley::Command mCommand;

    ley::Vec3<float> vCorners[8] = {
        { 1, -1, -5},
         { 1, -1, -3},
         { 1,  1, -5},
         { 1,  1, -3},
         {-1, -1, -5},
         {-1, -1, -3},
         {-1,  1, -5},
         {-1,  1, -3}
    };

    for (int i = 0; i < 8; ++i) {
        // Divide the x and y coordinates by the z coordinate to 
        // project the point onto the canvas
        float x_proj = vCorners[i].x / -vCorners[i].z + 5;
        float y_proj = vCorners[i].y / -vCorners[i].z + 5;
        SDL_Log("Projected Vcorner %d: x:%f, y:%f\n", i, x_proj, y_proj);
    }

    Point corners[8] = {
         { 1, -1, -5},
         { 1, -1, -3},
         { 1,  1, -5},
         { 1,  1, -3},
         {-1, -1, -5},
         {-1, -1, -3},
         {-1,  1, -5},
         {-1,  1, -3}
    };

    for (int i = 0; i < 8; ++i) {
        // Divide the x and y coordinates by the z coordinate to 
        // project the point onto the canvas
        float x_proj = corners[i][0] / -corners[i][2] + 5;
        float y_proj = corners[i][1] / -corners[i][2] + 5;
        SDL_Log("Projected corner %d: x:%f, y:%f\n", i, x_proj, y_proj);
    }


    while(programRunning) {
        mVideoSystem.frameStart();
        
        mVideoSystem.render();
        mVideoSystem.present();
        mCommand = mInputSystem.pollEvents();

        if(mCommand == ley::Command::quit) {
            programRunning = false;
        }
        if(mCommand == ley::Command::ins) {
            mModel.XDegreeUp();
        }
        if(mCommand == ley::Command::del) {
            mModel.XDegreeDown();
        }
        if(mCommand == ley::Command::home) {
            mModel.YDegreeUp();
        }
        if(mCommand == ley::Command::end) {
            mModel.YDegreeDown();
        }
        if(mCommand == ley::Command::pgup) {
            mModel.degreeUp();
            mModel.ZDegreeUp();
        }
        if(mCommand == ley::Command::space) {
            mModel.zeroDegress();
        }
        if(mCommand == ley::Command::pgdown) {
            mModel.degreeDown();
            mModel.ZDegreeDown();
        }
        if(mCommand == ley::Command::up) {
            mModel.up();
        }
        if(mCommand == ley::Command::down) {
            mModel.down();
        }
        if(mCommand == ley::Command::left) {
            mModel.left();
        }
        if(mCommand == ley::Command::right) {
            mModel.right();
        }

        mVideoSystem.clear();

        //update
        mModel.timer()->runFrame();
        if(mModel.timer()->hasExpired()) {
            mModel.degreeUp();
        }


        mVideoSystem.frameDelay();
    }

    return 1; 
}