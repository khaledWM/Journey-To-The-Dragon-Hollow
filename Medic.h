//
// Created by Khaled Mohamed on 2020-04-21.
//

/*                              Class Documentation
 * Medic class derived from the character class. The medic is a character that provides a
 * health boost to the hero character that comes in contact with it.The health boost is 10,
 *
 */

#ifndef MEDIC_H
#define MEDIC_H


#include "Character.h"

class Medic : public Character {
public:
    Medic(char= 'M', int= 10, int = 0, int= 0, bool= true);

    ~Medic();

    virtual void updateCharacterPosition();

private:
    bool reachedX;

};


#endif //FINALEXAM_MEDIC_H
