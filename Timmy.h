//
// Created by Khaled Mohamed on 2020-04-08.
//

/*                              Class Documentation
 *
 * Timmy class is a derived class from the character class,  timmy's health
 * is set to 15 and his strength is set to 3 and he has an armour of 3.
 * timmy moves across the dragon hollow from left to right
 * and he can either move 1 position forward or 1 position to the right or
 * 1 position to the left, when timmy takes damage it loses some of it's health depending
 * on the strength of the character s that it cam in contact with subtracted form timmy's armour
 * when timmy's health is 0 it is dead and it's character is just a ( '+' ) character.
 *
 *  void updateCharacterPosition: Function that determines timmy's movement sequence
 *  void damageTaken(int damage): Function that determines timmy's damage taken and weather the character
 *                                is dead or not.
 */
#ifndef TIMMY_H
#define TIMMY_H

#include "Character.h"


class Timmy : public Character {

public:
    Timmy(char= 'T', int= 15, int = 3, int= 3);

    ~Timmy();

    virtual void updateCharacterPosition();

    virtual void damageTaken(int);


private:

};

#endif //FINALEXAM_TIMMY_H
