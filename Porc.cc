//
// Created by Khaled Mohamed on 2020-04-08.
//

#include "Porc.h"

Porc::Porc(char n, int h, int s, int a) : Character(n, h, s, a) {

}

Porc::~Porc() {

}


void Porc::updateCharacterPosition() {
    if (posY == 1 || isDead()) {
        setName(' ');
    } else {
        posX = posX + (rand() % (1 + 1 - (-1))) + (-1);
        posY = posY - 1;
    }
}

void Porc::damageTaken(int damage) {
    Character::damageTaken(damage);
}

