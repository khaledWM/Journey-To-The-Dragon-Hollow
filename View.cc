//
// Created by Khaled Mohamed on 2020-04-20.
//

#include "View.h"

void View::showMenu(int &choice) {

    cout << endl;
    cout << "The Tortoise Chronicles: Journey to Dragon's Hollow" << endl << endl;
    cout << "Event:" << endl;
    cout << "  (0) Exit" << endl;
    cout << "  (1) Retrieve Emerald" << endl;

    cout << "Enter your selection: ";
    cin >> choice;
    if (choice == 0)
        return;

    while (choice < 1 || choice > 2) {
        cout << "Enter your selection: ";
        cin >> choice;
    }

}


void View::printStr(string str) {
    cout << str << endl;
}

void View::readInt(int &n) {
    cin >> n;
}


void View::readStr(string &str) {
    cin >> str;
}

void View::printInt(int n) {
    cout << n;
}
