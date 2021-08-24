//
// Created by Khaled Mohamed on 2020-04-20.
//

/*Class Documentation*
 * The view class will be interacting with the user.
 */

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>

using namespace std;

class View {

public:

    void showMenu(int &);

    void printStr(string);

    void readInt(int &);

    void readStr(string &str);

    void printInt(int n);
};


#endif //FINALEXAM_VIEW_H
