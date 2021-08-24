//
// Created by Khaled Mohamed on 2020-04-08.
//


/*                              Class Documentation
 *
 * Dorc class is a derived class from the character class, The dorc's health
 * is set to 5 and his strength is randomly picked between 6 and 8 (inclusive)
 * and he does not have an armour. The dorc moves across the dragon hollow from right
 * to left and he can either move 1 position forward or 1 position to the right or
 * 1 position to the left, when the dorc takes damage it loses some of it's health depending
 * on the strength of the character that it cam in contact with, when the dorc's health is 0
 * it is dead and it's character is just a space character ( ' ' ).
 *
 *  void updateCharacterPosition: Function that determines dorc's movement sequence
 *  void damageTaken(int damage): Function that determines dorc's damage taken and weather the character
 *                                is dead or not.
 */

#ifndef DORC_H
#define DORC_H

#include "Character.h"
#include "cstdlib"
#include <ctime>
#include "iostream"

class Dorc : public Character {

public:

    Dorc(char= 'd', int= 5, int = (rand() % (8 - 6 + 1)) + 6, int= 0);

    ~Dorc();

    virtual void updateCharacterPosition();

    virtual void damageTaken(int damage);

private:


};

#endif //FINALEXAM_DORC_H
