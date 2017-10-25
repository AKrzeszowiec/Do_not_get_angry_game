#include "Tscreen.h"
#include "Tboard.h"
#include "ncurses.h"

void keyboard_handling();

Tscreen::Tscreen()
{
    Tboard board;
    board.print_yourself();
    keyboard_handling();
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

