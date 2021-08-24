//
// Created by Khaled Mohamed on 2020-04-22.
//

#include "Chaser.h"


Chaser::Chaser(char n, int h, int s, int a, bool p) : Character(n, h, s, a, p) {
    reachedY = true;
}

Chaser::~Chaser() {


}


void Chaser::updateCharacterPosition() {
    if (posY == 38) {
        reachedY = true;
    }
    if (posY == 1) {
        reachedY = false;
    }

    if (reachedY) {
        posY = posY - 2;
    } else {
        posY = posY + 2;
    }
}
