//
// Created by Khaled Mohamed on 2020-04-12.
//

#include "GameControl.h"
#include "random.cc"


GameControl::GameControl() {
    display.initializeDisplay(' ');
    display.fillInDisplay('-', '|', '=');
}

GameControl::~GameControl() {
    list<Character *>::iterator it;
    for (it = characters.begin(); it != characters.end(); ++it) {
        delete *it;
    }
}

void GameControl::setInitialCharacters(Character *timmy, Character *harold, Character *dragon) {
    characters.push_back(timmy);
    characters.push_back(harold);
    characters.push_back(dragon);
    timmy->setPos(random(6), 1);
    harold->setPos(random(6), 1);
    dragon->setPos(3, 38);
    display.placeOnBoard('*', 4, 41);
    list<Character *>::iterator it;
    for (it = characters.begin(); it != characters.end(); ++it) {
        display.placeOnBoard((*it)->getName(), (*it)->getPosX(), (*it)->getPosY());
    }
}


void GameControl::setPowerOnMap(Character *chaser, Character *armour, Character *et, Character *medic) {
    characters.push_back(chaser);
    characters.push_back(armour);
    characters.push_back(et);
    characters.push_back(medic);
    chaser->setPos(checkBoundaryX(random(6)), (rand() % (38 - 25 + 1)) + 25);
    armour->setPos(checkBoundaryX(random(6)), armour->getPosY());
    et->setPos(checkBoundaryX(random(6)), et->getPosY());
    medic->setPos(checkBoundaryX(random(6)), medic->getPosY());
    list<Character *>::iterator it;
    for (it = characters.begin(); it != characters.end(); ++it) {
        display.placeOnBoard((*it)->getName(), (*it)->getPosX(), (*it)->getPosY());
    }
}

void GameControl::startGame() {
    clearBoard();
    int r = random(6);
    Character *timmy = new Timmy();
    Character *dragon = new Dragon();
    Character *harold = new Harold();
    Character *chaser = new Chaser();
    Character *armour = new Armour();
    Character *extra = new ExtraStrength();
    Character *medic = new Medic();
    setInitialCharacters(timmy, harold, dragon);
    setPowerOnMap(chaser, armour, extra, medic);
    cout << display << endl;
    while (1) {
        sleep(1);
        system("clear");
        if ((timmy->isDead() &&
             harold->isDead())) {
            cout << display << endl;
            throw ((string) "Game over Timmy and Harold are dead. Please try again.");
        }
        bool create = (rand() % 100) < 60;
        if (create) {
            createFighter();
        }
        updatePositions();
        checkCollisions(timmy, harold);
        checkForMedicPowerUps(harold, timmy, medic);
        checkForArmourPowerUps(harold, timmy, armour);
        checkForStrengthPowerUps(harold, timmy, extra);
        checkForChaser(harold, timmy, chaser);
        savedTheEmerald(timmy, harold, dragon);
        cout << display << endl;

        if (harold->getSavedTheEmerald()) {
            throw ((string) "HAROLD has SAVED THE EMERALD!!!");
        }
        else if (timmy->getSavedTheEmerald()) {
            throw ((string) " TIMMY HAS SAVED THE EMERALD!!!");
        }
    }
}

void GameControl::updatePositions() {
    list<Character *>::iterator it;
    for (it = characters.begin(); it != characters.end(); ++it) {
        display.removeOldCharacters((*it)->getName(), ' ');
    }
    for (it = characters.begin(); it != characters.end(); ++it) {
        (*it)->updateCharacterPosition();
        (*it)->setPos(checkBoundaryX((*it)->getPosX()), checkBoundaryY((*it)->getPosY()));
        display.placeOnBoard((*it)->getName(), (*it)->getPosX(), (*it)->getPosY());
    }
}

int GameControl::checkBoundaryX(int x) {
    if (x >= 6) {
        x = display.getRows() - 2;
    }
    if (x <= 0) {
        x = 1;
    }
    return x;
}

int GameControl::checkBoundaryY(int y) {
    if (y >= 38) {
        y = 38;
    }
    if (y <= 1) {
        y = 1;
    }
    return y;
}

void GameControl::checkCollisions(Character *timmy, Character *harold) {
    list<Character *>::iterator it;
    for (it = characters.begin(); it != characters.end(); ++it) {
        if ((*it) != harold && (*it) != timmy && !(*it)->getPower()) {
            if (harold->getPosX() == (*it)->getPosX() && harold->getPosY() == (*it)->getPosY() && !harold->isDead()) {
                harold->damageTaken((*it)->getStrength());
                (*it)->damageTaken(harold->getStrength());
            }
            if (timmy->getPosX() == (*it)->getPosX() && timmy->getPosY() == (*it)->getPosY() && !timmy->isDead()) {
                timmy->damageTaken((*it)->getStrength());
                (*it)->damageTaken(timmy->getStrength());
            }
        }
    }
}

void GameControl::savedTheEmerald(Character *timmy, Character *harold, Character *dragon) {
    list<Character *>::iterator it;
    for (it = characters.begin(); it != characters.end(); ++it) {
        if ((*it) == harold || (*it) == timmy) {
            if (!(*it)->isDead() && (*it)->getPosY() == dragon->getPosY()) {
                if (((*it)->getPosX() == 2 || (*it)->getPosX() == 3 || (*it)->getPosX() == 4) && !(*it)->isDead())
                    (*it)->setSaved();
            }
        }
    }
}

void GameControl::createFighter() {
    int randNum = (rand() % 3) + 1;
    Character *orc;
    if (randNum == 1) {
        orc = new Borc();
    } else if (randNum == 2) {
        orc = new Dorc();
    } else {
        orc = new Porc();
    }
    orc->setPos(random(6), 37);
    characters.push_back(orc);
    display.placeOnBoard(orc->getName(), orc->getPosX(), orc->getPosY());
}

void GameControl::clearBoard() {
    list<Character *>::iterator it;
    for (it = characters.begin(); it != characters.end(); ++it) {
        display.removeOldCharacters((*it)->getName(), ' ');
    }
    for (it = characters.begin(); it != characters.end(); ++it) {
        delete *it;
    }
    characters.clear();
}

void GameControl::checkForMedicPowerUps(Character *harold, Character *timmy, Character *medic) {
    if (harold->getPosX() == medic->getPosX() && harold->getPosY() == medic->getPosY() && !harold->isDead()) {
        harold->setHealth(medic->getHealth());
        cout << "Harold has received the medicine boost" << endl;
        cout <<"Harold's Health: "<<harold->getHealth() << endl;
        sleep(1);
    }
    if (timmy->getPosX() == medic->getPosX() && timmy->getPosY() == medic->getPosY() && !timmy->isDead()) {
        timmy->setHealth(medic->getHealth());
        cout << "Timmy has received the medicine boost" << endl;
        cout <<"Timmy's Health: "<<timmy->getHealth() << endl;
        sleep(1);
    }
}

void GameControl::checkForArmourPowerUps(Character *harold, Character *timmy, Character *armour) {
    if (harold->getPosX() == armour->getPosX() && harold->getPosY() == armour->getPosY() && !harold->isDead()) {
        harold->setArmour(armour->getArmour());
        cout << "Harold has received the Armour boost" << endl;
        cout <<"Harold's Armour: "<< harold->getArmour() << endl;
        sleep(1);
    }
    if (timmy->getPosX() == armour->getPosX() && timmy->getPosY() == armour->getPosY() && !timmy->isDead()) {
        timmy->setArmour(armour->getArmour());
        cout << "Timmy has received the Armour boost" << endl;
        cout <<"Timmy's Armour: "<< timmy->getArmour() << endl;
        sleep(1);
    }
}

void GameControl::checkForStrengthPowerUps(Character *harold, Character *timmy, Character *strength) {

    if (harold->getPosX() == strength->getPosX() && harold->getPosY() == strength->getPosY() && !harold->isDead()) {
        harold->setStrength(strength->getStrength());
        cout << "Harold has received the Strength boost" << endl;
        cout <<"Harold's Strength: "<< harold->getStrength() << endl;
        sleep(1);
    }
    if (timmy->getPosX() == strength->getPosX() && timmy->getPosY() == strength->getPosY() && !timmy->isDead()) {
        timmy->setStrength(strength->getStrength());
        cout << "Timmy has received the Strength boost" << endl;
        cout <<"Timmy's Strength: "<< timmy->getStrength() << endl;
        sleep(1);
    }
}

void GameControl::checkForChaser(Character *harold, Character *timmy, Character *chaser) {
    if (harold->getPosX() == chaser->getPosX() && harold->getPosY() == chaser->getPosY() && !harold->isDead()) {
        harold->setHealth(0);
        harold->setName('+');
        cout << "Harold has been caught by the Chaser" << endl;
        cout <<"Harold's Health: "<< harold->getHealth() << endl;
        sleep(1);
    }
    if (timmy->getPosX() == chaser->getPosX() && timmy->getPosY() == chaser->getPosY() && !timmy->isDead()) {
        timmy->setHealth(0);
        timmy->setName('+');
        cout << "Timmy has been caught by the Chaser" << endl;
        cout <<"Timmy's Health: "<< timmy->getHealth() << endl;
        sleep(1);
    }
}










