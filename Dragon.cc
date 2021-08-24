//
// Created by Khaled Mohamed on 2020-04-08.
//

#include "Dragon.h"

Dragon::Dragon(char n, int h, int s) : Character(n, h, s) {

    reached = false;
}

Dragon::~Dragon() {
}

void Dragon::updateCharacterPosition() {
    if (posX == 2) {
        reached = true;
    }
    if (posX == 4) {
        reached = false;
    }

    if (reached) {
        posX++;
    } else {
        posX--;
    }
}

