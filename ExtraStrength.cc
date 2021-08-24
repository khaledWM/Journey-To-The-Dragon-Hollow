//
// Created by Khaled Mohamed on 2020-04-21.
//

#include "ExtraStrength.h"


ExtraStrength::ExtraStrength(char n, int h, int s, int a, bool p) : Character(n, h, s, a, p) {
    posX = 3;
    posY = 21;
    reachedX = false;
}


ExtraStrength::~ExtraStrength() {

}

void ExtraStrength::updateCharacterPosition() {
    if (posX == 1) {
        reachedX = true;
    }
    if (posX == 5) {
        reachedX = false;
    }

    if (reachedX) {
        posX++;
    } else {
        posX--;
    }
}





