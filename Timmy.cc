//
// Created by Khaled Mohamed on 2020-04-08.
//

#include "Timmy.h"

Timmy::Timmy(char n, int h, int s, int a) : Character(n, h, s, a) {

}


Timmy::~Timmy() {

}

void Timmy::updateCharacterPosition() {
    if (!isDead()) {
        if (posX == 1 && posY == 38) {
            posX++;
        } else if (posX == 5 && posY == 38) {
            posX--;
        } else {
            posX = posX + (rand() % (1 + 1 - (-1))) + (-1);
            posY = posY + 1;
        }
    }
}

void Timmy::damageTaken(int damage) {
    if (!isDead()) {
        if (getHealth() - (damage - getArmour()) <= 0) {
            setHealth(0);
            setName('+');
        } else {
            setHealth(getHealth() - (damage - getArmour()));
        }
    }
}



