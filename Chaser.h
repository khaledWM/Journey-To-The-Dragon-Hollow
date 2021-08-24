//
// Created by Khaled Mohamed on 2020-04-22.
//

/*                              Class Documentation
 *
 * The chaser character is a character that tries to catch the heros on the map, when they come in contact the heros
 * instantly die, his movement pattern is that he spawns randomly across the map and then he jumps horizontally by 2 positions
 *
 */

#ifndef CHASER_H
#define CHASER_H


#include "Character.h"


class Chaser : public Character {
public:
    Chaser(char = 'C', int = 30, int = 14, int= 0, bool= true);

    ~Chaser();

private:

    virtual void updateCharacterPosition();

    bool reachedY;

};


#endif //FINALEXAM_CHASER_H
