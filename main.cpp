#include <iostream>
#include <ncurses.h>
using namespace std;

void keyboard_handling(); //function used to handle interaction with user through keyboard

class Tcoord {
public:
    int x;
    int y;
    Tcoord(int x, int y) : x(x), y(y) {}
};


class Tboard {
    char temporary_board[11][11];
    Tcoord play_fields[40]={Tcoord(4,0),Tcoord(4,2),Tcoord(4,4),Tcoord(4,6),Tcoord(4,8),Tcoord(3,8),Tcoord(2,8),Tcoord(1,8),Tcoord(0,8),Tcoord(0,10),Tcoord(0,12),Tcoord(1,12),Tcoord(2,12),Tcoord(3,12),Tcoord(4,12),Tcoord(4,14),Tcoord(4,16),Tcoord(4,18),Tcoord(4,20),Tcoord(5,20),Tcoord(6,20),Tcoord(6,18),Tcoord(6,16),Tcoord(6,14),Tcoord(6,12),Tcoord(7,12),Tcoord(8,12),Tcoord(9,12),Tcoord(10,12),Tcoord(10,10),Tcoord(10,8),Tcoord(9,8),Tcoord(8,8),Tcoord(7,8),Tcoord(6,8),Tcoord(6,6),Tcoord(6,4),Tcoord(6,2),Tcoord(6,0),Tcoord(5,0)};;
public:
    void print_yourself() {
    initscr();
    for (int i=0; i<40; i++) {
        mvaddch(play_fields[i].x,play_fields[i].y,'x');
    }
    keyboard_handling();
    }
};

int main()
{
Tboard screen;
screen.print_yourself();
    return 0;
}

void keyboard_handling(){
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    //start_color();
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
