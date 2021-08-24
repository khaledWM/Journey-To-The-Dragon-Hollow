//
// Created by Khaled Mohamed on 2020-04-08.
//

#include "Dorc.h"


Dorc::Dorc(char n, int h, int s, int a) : Character(n, h, s, a) {

}

Dorc::~Dorc() {

}


void Dorc::updateCharacterPosition() {
    if (posY == 1 || isDead()) {
        setName(' ');
    } else {
        posX = posX + (rand() % (1 + 1 - (-1))) + (-1);
        posY = posY - 1;
    }
}

void Dorc::damageTaken(int damage) {
    Character::damageTaken(damage);
}
