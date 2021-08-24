//
// Created by Khaled Mohamed on 2020-04-08.
//

/*                              Class Documentation
 *
 * Harold class is a derived class from the character class,  harold's health
 * is set to 15 and his strength is set to 5 and he has an armour of 1.
 * harold moves across the dragon hollow from left to right
 * and he can either move 1 position forward or 1 position to the right or
 * 1 position to the left, when harold takes damage it loses some of it's health depending
 * on the strength of the character s that it cam in contact with subtracted form harold's armour
 * when harold's health is 0 it is dead and it's character is just a ( '+' ) character.
 *
 *  void updateCharacterPosition: Function that determines harold's movement sequence
 *  void damageTaken(int damage): Function that determines harold's damage taken and weather the character
 *                                is dead or not.
 */

#ifndef HAROLD_H
#define HAROLD_H

#include "Character.h"

class Harold : public Character {

public:
    Harold(char= 'H', int= 15, int = 5, int= 1);

    ~Harold();

    virtual void updateCharacterPosition();

    void damageTaken(int damage);

private:


};

#endif //FINALEXAM_HAROLD_H
