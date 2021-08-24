

#include "Control.h"
#include <ncurses.h>
#include <unistd.h>

int main() {
    srand(time(NULL));
    Control control;

    control.launch();

}


