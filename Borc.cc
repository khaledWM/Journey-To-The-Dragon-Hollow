//
// Created by Khaled Mohamed on 2020-04-08.
//

#include "Borc.h"


Borc::Borc(char n, int h, int s, int a) : Character(n, h, s, a) {

}

Borc::~Borc() {

}


void Borc::damageTaken(int damage) {
    Character::damageTaken(damage);
}

void Borc::updateCharacterPosition() {
    if (posY == 1) {
        setName(' ');
    } else {
        posX = posX + (rand() % (1 + 1 - (-1))) + (-1);
        posY = posY - 1;
    }
}
