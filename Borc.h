//
// Created by Khaled Mohamed on 2020-04-08.
//

/*                              Class Documentation
 *
 * Borc class is a derived class from the character class, The borc's health
 * is set to 5 and his strength is randomly picked between 8 and 11 (inclusive)
 * and he does not have an armour. The borc moves across the dragon hollow from right
 * to left and he can either move 1 position forward or 1 position to the right or
 * 1 position to the left, when the borc takes damage it loses some of it's health depending
 * on the strength of the character that it cam in contact with, when the borc's health is 0
 * it is dead and it's character is just a space character ( ' ' ).
 *
 *  void updateCharacterPosition: Function that determines borc's movement sequence
 *  void damageTaken(int damage): Function that determines borc's damage taken and weather the character
 *                                is dead or not.
 */



#ifndef BORC_H
#define BORC_H

#include "Character.h"


class Borc : public Character {

public:
    Borc(char= 'b', int= 5, int = (rand() % (11 - 8 + 1)) + 8, int= 0);

    ~Borc();

    virtual void updateCharacterPosition();

    virtual void damageTaken(int damage);

private:
};

#endif //FINALEXAM_BORC_H
