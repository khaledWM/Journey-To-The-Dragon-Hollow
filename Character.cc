//
// Created by Khaled Mohamed on 2020-04-08.
//

#include "Character.h"


Character::Character(char n, int h, int s, int a, bool p) {
    name = n;
    health = h;
    strength = s;
    armour = a;
    savedTheEmerald = false;
    isAPowerUp = p;
}

Character::~Character() {

}


int Character::getHealth() {

    return health;
}

char Character::getName() {
    return name;
}

int Character::getStrength() {
    return strength;
}

bool Character::isDead() {
    return health <= 0;
}

int Character::getArmour() {
    return armour;
}

int Character::getPosX() {
    return posX;
}

int Character::getPosY() {
    return posY;
}

void Character::setPos(int x, int y) {
    posX = x;
    posY = y;
}

void Character::setName(char x) {
    name = x;
}

void Character::setHealth(int h) {
    if (h <= 0) {
        health = 0;
        return;
    }
    health = h;
}

bool Character::getSavedTheEmerald() {
    return savedTheEmerald;
}

void Character::setSaved() {
    savedTheEmerald = true;
}

void Character::updateCharacterPosition() {}

void Character::damageTaken(int damage) {
    if (!isDead()) {
        if (getHealth() - (damage - getArmour()) <= 0) {
            setHealth(0);
            setName(' ');
        } else {
            setHealth(getHealth() - (damage - getArmour()));
        }
    }
}

bool Character::getPower() {
    return isAPowerUp;
}

void Character::setArmour(int a) {
    armour = a;
}

void Character::setStrength(int s) {
    strength = s;
}





