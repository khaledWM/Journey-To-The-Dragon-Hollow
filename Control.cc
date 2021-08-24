//
// Created by Khaled Mohamed on 2020-04-08.
//

#include "Control.h"

void Control::launch() {

    int choice;
    while (1) {
        view.showMenu(choice);
        if (choice == 0)
            break;

        if (choice == 1) {
            try {
                control.startGame();
            } catch (string error) {
                view.printStr(error);
            }
        }
    }
}
