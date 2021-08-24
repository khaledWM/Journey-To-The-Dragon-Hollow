//
// Created by Khaled Mohamed on 2020-04-21.
//

#include "Armour.h"

Armour::Armour(char n, int h, int s, int a, bool p) : Character(n, h, s, a, p) {
    reachedX = false;
    posX = 3;
    posY = 14;
}


Armour::~Armour() {

}

void Armour::updateCharacterPosition() {
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



