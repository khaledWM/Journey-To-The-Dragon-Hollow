//
// Created by Khaled Mohamed on 2020-04-08.
//

/*                              Class Documentation
 *
 * Porc class is a derived class from the character class, The porc's health
 * is set to 5 and his strength is randomly picked between 4 and 5 (inclusive)
 * and he does not have an armour. The porc moves across the dragon hollow from right
 * to left and he can either move 1 position forward or 1 position to the right or
 * 1 position to the left, when the porc takes damage it loses some of it's health depending
 * on the strength of the character that it cam in contact with, when the porc's health is 0
 * it is dead and it's character is just a space character ( ' ' ).
 *
 *  void updateCharacterPosition: Function that determines porc's movement sequence
 *  void damageTaken(int damage): Function that determines porc's damage taken and weather the character
 *                                is dead or not.
 */


#ifndef PORC_H
#define PORC_H

#include "Character.h"

class Porc : public Character {

public:

    Porc(char= 'p', int= 5, int = (rand() % (5 - 4 + 1)) + 4, int= 0);

    ~Porc();

    virtual void updateCharacterPosition();

    virtual void damageTaken(int damage);

private:


};

#endif //FINALEXAM_PORC_H
