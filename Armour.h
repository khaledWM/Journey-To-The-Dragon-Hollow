//
// Created by Khaled Mohamed on 2020-04-21.
//

/*                              Class Documentation
 * Armour class derived from the character class. The armour is a character that provides a
 * armour boost to the hero character that comes in contact with it.The armour boost is 10,
 *
 */


#ifndef ARMOUR_H
#define ARMOUR_H


#include "Character.h"

class Armour : public Character {
public:
    Armour(char= 'A', int= 0, int = 0, int= 10, bool= true);

    ~Armour();

    virtual void updateCharacterPosition();

private:
    bool reachedX;

};


#endif //FINALEXAM_ARMOUR_H
