#include <iostream>

#include "Input.h"
#include "Video.h"

int main() {
    bool programRunning = true;

    ley::Video mVideoSystem;
    ley::Input mInputSystem;
    ley::Command mCommand;

    while(programRunning) {

        mVideoSystem.present();
        mCommand = mInputSystem.pollEvents();

        if(mCommand == ley::Command::quit) {
            programRunning = false;
        }
    }

    return 1;
}