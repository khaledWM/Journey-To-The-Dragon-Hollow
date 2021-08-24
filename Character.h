
// Created by Khaled Mohamed on 2020-04-08.


/*                              Class Documentation
 * The character class is the base class for all the characters in the game.
 * this class is an abstract class that mostly has getters and setters and the only functions.
 *
 *Functions:
 * damageTaken(int): handles the damage taken by a character and this is virtual the implementation is in the derived
 *                  classes, some classes use the implementation of the base class and some classes override the implementation
 *
 *updateCharacterPosition(): pure virtual function that does not get implemented in the base class, it is only implemented
 *                           in the derived classes with each character having it's own movement sequence
 *
 */


#ifndef CHARACTER_H
#define CHARACTER_H

#include "iomanip"
#include "iostream"
#include "string"

using namespace std;

class Character {
public:

    Character(char = 'N', int= 0, int = 0, int = 0, bool= false);

    virtual~Character();

    int getHealth();

    char getName();

    int getArmour();

    int getStrength();

    int getPosX();

    int getPosY();

    bool isDead();

    bool getSavedTheEmerald();

    void setPos(int, int);

    void setName(char x);

    void setHealth(int h);

    void setSaved();

    bool getPower();

    void setArmour(int);

    void setStrength(int);


    virtual void damageTaken(int);

    virtual void updateCharacterPosition() = 0;

protected:
    int posX;
    int posY;


private:
    int health;
    int strength;
    char name;
    int armour;
    bool savedTheEmerald;
    bool isAPowerUp;
};


#endif //FINALEXAM_CHARACTER_H
