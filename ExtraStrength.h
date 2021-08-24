//
// Created by Khaled Mohamed on 2020-04-21.
//
/*                              Class Documentation
 * ExtraStrength class derived from the character class. The medic is a character that provides a
 * strength boost to the hero character that comes in contact with it.The strength boost is 10,
 *
 */

#ifndef EXTRASTRENGTH_H
#define EXTRASTRENGTH_H

#include "Character.h"

class ExtraStrength : public Character {
public:
    ExtraStrength(char= 'E', int= 0, int = 10, int= 0, bool= true);

    ~ExtraStrength();

    virtual void updateCharacterPosition();

private:
    bool reachedX;
};


#endif //FINALEXAM_EXTRASTRENGTH_H
