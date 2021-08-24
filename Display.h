//
// Created by Khaled Mohamed on 2020-04-09.
//

/*                              Class Documentation
 * The display class is the class responsible for creating a game map,
 * the class is a class template meaning it provides a specification for generating
 * classes based on parameters.The display is a 2-dimensional array and it's elements are
 * declared as a double pointer of type T, where the 2-dimensional array is represented as a dynamically allocated array
 * of dynamically allocated arrays.
 *
 * Functions:
 *
 * Constructor: initializes the rows and columns, rows are set to 7 and columns are set to 42.
 * Destructor: deallocate the memory for the 2-dimensional array
 *
 *  initializeDisplay(T): A function that dynamically allocates an array of dynamically allocated arrays
 *                            so for the size of the rows which is 7 an array of pointer will be allocated of size
 *                            42 and each pointer of each row will be pointing to it's dynamically allocated array
 *                            The display is then initially filled up with one element of type T before adding other
 *                            elements to it.
 *
 *
 * void fillInDisplay(const T &, const T &, const T &): A function that takes 3 elements of type T and builds the display
 *                                                      depending on where the elements are supposed to be placed.
 *
 * boundaryCheckX(int): makes a boundary check on the position of the characters in the map to make sure it's not
 *                      out of bounds (not needed just decided to leave it for an extra check)
 *
 *
 * removeOldCharacters(const T &, const T &): takes in a T element that is on the board and removes it by placing another
 *                                            element depending on the type of object used.
 *
 *
 * placeOnBoard(const T &, int, int): takes an element of type T, a position X and a position Y and places that element
 *                                    on the board.
 *
 *operator<<: global function used to print out the 2d array to the user.
 */



#ifndef DISPLAY_H
#define DISPLAY_H

#include <unistd.h>
#include "iostream"

using namespace std;

template<class T>
class Display {
    template<class V>
    friend ostream &operator<<(ostream &, const Display<V> &);

public:

    Display();

    ~Display();

    T **initializeDisplay(T);

    int getRows();

    int boundaryCheckX(int);

    void removeOldCharacters(const T &, const T &);

    void fillInDisplay(const T &, const T &, const T &);

    void placeOnBoard(const T &, int, int);


private:
    T **elements;
    int rows;
    int cols;


};

template<class T>
Display<T>::Display() {
    rows = 7;
    cols = 42;

}

template<class T>
Display<T>::~Display() {
    for (int i = 0; i < rows; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

template<class T>
int Display<T>::getRows() {
    return rows;
}

template<class T>
T **Display<T>::initializeDisplay(T elem) {
    elements = new T *[rows];
    for (int i = 0; i < rows; ++i) {
        elements[i] = new T[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            elements[i][j] = elem;
        }
    }
    return elements;
}

template<class T>
void Display<T>::fillInDisplay(const T &elemR, const T &elemC, const T &elemA) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 4; j < cols; ++j) {
            elements[0][j - 3] = elemR;
            elements[rows - 1][j - 3] = elemR;
            elements[i][0] = elemC;
            elements[i][39] = elemC;
        }
    }
    for (int i = 2; i < 5; ++i) {
        for (int j = 39; j < 40; ++j) {
            elements[i][j] = elemA;
        }
    }
}


template<class T>
void Display<T>::placeOnBoard(const T &character, int posX, int posY) {
    elements[boundaryCheckX(posX)][posY] = character;
}

template<class T>
int Display<T>::boundaryCheckX(int x) {
    if (x >= 6) {
        x = rows - 2;
    }
    if (x <= 0) {
        x = 1;
    }
    return x;
}

template<class T>
void Display<T>::removeOldCharacters(const T &character, const T &element) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (elements[i][j] == character)
                elements[i][j] = element;
        }
    }
}

template<class T>
ostream &operator<<(ostream &out, const Display<T> &display) {
    for (int i = 0; i < display.rows; ++i) {
        for (int j = 0; j < display.cols; ++j) {
            out << display.elements[i][j];
        }
        out << endl;
    }
    return out;
}


#endif //FINALEXAM_DISPLAY_H
