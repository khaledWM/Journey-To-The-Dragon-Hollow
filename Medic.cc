//
// Created by Khaled Mohamed on 2020-04-21.
//

#include "Medic.h"


Medic::Medic(char n, int h, int s, int a, bool p) : Character(n, h, s, a, p) {
    posX = 3;
    posY = 27;
    reachedX = false;
}

Medic::~Medic() {

}


void Medic::updateCharacterPosition() {

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



