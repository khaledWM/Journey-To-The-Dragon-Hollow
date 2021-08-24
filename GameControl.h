//
// Created by Khaled Mohamed on 2020-04-12.
//

/*                                       Class Documentation
 *
 *The game_control class responsible for handling all the gameplay of all types, using the list collection class
 * from the stl library this class decides where elements should go on the display and it checks for collisons
 * between characters and weather a character has recieved a power up or not, the class also makes boundary checks
 * and updates the movements of the players by iterating over the characters list and calling their updateMovement function
 * it also iterates over the list when handling collisions to update health and status of living.
 *
 * Functions:
 *
 * Constructor: the constructor calls the initializeDisplay function from display class that dynamically allocates the
 *              elements of the display and because the display is a template class we pass in the element (' '), then we call
 *              the fillInDisplay function that takes the elemnts required to build up the dragon's hollow.
 *
 * Destructor: deallocate all the dynamically allocated characters in the stl list.
 *
 * setInitialCharacters(): function that generats random position for the characters and places them on the map
 *
 * setPowerOnMap(): function that generates a random position for the power ups and places them on the map.
 *
 * updatePositions(): function that updates all the game character position using the update movement function of
 *                    each character and then make a boundary check on the positions, if any position is out of bounds
 *                    it adjusts the positon and sets the character's position to the new postion and then displays it on the map
 *
 * checkCollisions(): checks weather timmy or harold have come in contact with an orc or a dragon and updates their health and status
 *                    of living accordingly
 *
 * checkBoundaryX/checkBoundaryY: makes a boundary check.
 *
 * savedTheEmerald(): checks if timmy or harold have retrieved the emerald.
 *
 * createFighter(): creates a new fighter randomly from 3 different fighters: Porc,Borc or Dorc
 *
 * checkForMedicPowerUps: checks if timmy or harold have come in contact with the health boost character and updates health accordingly.
 *
 * startGame(): game loop that updates positions, checks for collisions, checks for power ups and if a hero has retrieved the emerald.
 *              the function terminates if both heros are dead or 1 hero has retrieved the emerald.
 *
 * clearBoard(): removes all characters of the board and deallocates memory of characters inside the list so if a user decides to restart the game,
 *               all previous characters have been removed.
 */


#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H


#include "Character.h"
#include <list>
#include "Display.h"
#include "Borc.h"
#include "Dorc.h"
#include "Porc.h"
#include "Dragon.h"
#include "Timmy.h"
#include "Harold.h"
#include "Armour.h"
#include "ExtraStrength.h"
#include "Medic.h"
#include <unistd.h>
#include "Chaser.h"

class GameControl {

public:
    GameControl();

    ~GameControl();

    void startGame();

private:
    list<Character *> characters;
    Display<char> display;

    void updatePositions();

    int checkBoundaryX(int);

    int checkBoundaryY(int);

    void savedTheEmerald(Character *, Character *, Character *);

    void checkCollisions(Character *, Character *);

    void createFighter();

    void setInitialCharacters(Character *, Character *, Character *);

    void clearBoard();

    void setPowerOnMap(Character *, Character *, Character *, Character *);

    void checkForMedicPowerUps(Character *, Character *, Character *);

    void checkForArmourPowerUps(Character *, Character *, Character *);

    void checkForStrengthPowerUps(Character *, Character *, Character *);

    void checkForChaser(Character *, Character *, Character *);
};


#endif //FINALEXAM_GAME_CONTROL_H
