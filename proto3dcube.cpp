#include <iostream>

#include "Input.h"
#include "Video.h"
#include "Model.h"

int main() {
    bool programRunning = true;

    ley::Model mModel;
    ley::Video mVideoSystem(&mModel);
    ley::Input mInputSystem;
    ley::Command mCommand;

    while(programRunning) {
        mVideoSystem.frameStart();
        
        mVideoSystem.render();
        mVideoSystem.present();
        mCommand = mInputSystem.pollEvents();

        if(mCommand == ley::Command::quit) {
            programRunning = false;
        }
        if(mCommand == ley::Command::pgup) {
            mModel.degreeUp();
        }
        if(mCommand == ley::Command::pgdown) {
            mModel.degreeDown();
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

        mVideoSystem.frameDelay();
    }

    return 1;
}