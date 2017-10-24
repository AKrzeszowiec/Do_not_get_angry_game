#include <iostream>
#include <ncurses.h>
using namespace std;

void keyboard_handling(); //function used to handle interaction with user through keyboard

int main()
{
    return 0;
}

void keyboard_handling(){
    initscr();
    noecho();
    keypad(stdscr, true);
    //start_color();
    bool ending=false;
    while(!ending){
        int c=getch();
        switch(c)
        {
        case 27 //esc
            ending=true;
            break;
        case 4 //left arrow
            break;
        case 5 //right arrow
            break;
        case 3 //up arrow
            break;
        case 2 //down arrow
            break;
        }
    }
    endwin();
}
