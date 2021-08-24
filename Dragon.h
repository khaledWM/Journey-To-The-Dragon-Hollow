//
// Created by Khaled Mohamed on 2020-04-08.
//


/*                              Class Documentation
 *
 * Dragon class is a derived class that inherits from the Character class.
 * The dragon's movement is a vertical movement where he reaches the top
 * of the cave and then moves back down and so on, the dragon's health and strength
 * does not allow him to die even if he comes in contact with another character.
 *
 *  void updateCharacterPosition: Function that determines dragon's movement sequence.
 */


#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"

class Dragon : public Character {

public:
    Dragon(char= 'D', int= 10000, int = 10000);

    ~Dragon();

    virtual void updateCharacterPosition();

private:
    bool reached;

};

#endif //FINALEXAM_DRAGON_H
