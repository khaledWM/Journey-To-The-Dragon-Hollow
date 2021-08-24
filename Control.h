//
// Created by Khaled Mohamed on 2020-04-08.
//

/*                                      Class Documentation
 *
 * This will be responsible for thee control flow of the program.
 * This class has a GameControl object and a View object for one
 * and when the program starts it prints out the menu from the view
 * object and depending on what the user enters the program will either
 * exit or the quest game will be launched
 */


#ifndef CONTROL_H
#define CONTROL_H


#include "GameControl.h"
#include "View.h"

class Control {
public:

    void launch();

private:
    GameControl control;
    View view;

};


#endif //FINALEXAM_CONTROL_H
