#include <iostream>
#include <ncurses.h>
#include "Tboard.h"
using namespace std;

void keyboard_handling(); //function used to handle interaction with user through keyboard


int main()
{
Tboard screen;
screen.print_yourself();
keyboard_handling();
    return 0;
}

void keyboard_handling(){
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    bool ending=false;
    while(!ending){
        int c=getch();
        switch(c)
        {
        case 27: //esc
            ending=true;
            break;
        case 4: //left arrow
            break;
        case 5: //right arrow
            break;
        case 3: //up arrow
            break;
        case 2: //down arrow
            break;
        }
    }
    endwin();
}
