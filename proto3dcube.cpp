#include <iostream>

#include "Input.h"
#include "Video.h"

int main() {
    bool programRunning = true;

    ley::Video mVideoSystem;
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

        mVideoSystem.clear();

        mVideoSystem.frameDelay();
    }

    return 1;
}