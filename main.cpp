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
    Tcoord play_fields[40]={Tcoord(4,0),Tcoord(4,1),Tcoord(4,2),Tcoord(4,3),Tcoord(4,4),Tcoord(3,4),Tcoord(2,4),Tcoord(1,4),Tcoord(0,4),Tcoord(0,5),Tcoord(0,6),Tcoord(1,6),Tcoord(2,6),Tcoord(3,6),Tcoord(4,6),Tcoord(4,7),Tcoord(4,8),Tcoord(4,9),Tcoord(4,10),Tcoord(5,10),Tcoord(6,10),Tcoord(6,9),Tcoord(6,8),Tcoord(6,7),Tcoord(6,6),Tcoord(7,6),Tcoord(8,6),Tcoord(9,6),Tcoord(10,6),Tcoord(10,5),Tcoord(10,4),Tcoord(9,4),Tcoord(8,4),Tcoord(7,4),Tcoord(6,4),Tcoord(6,3),Tcoord(6,2),Tcoord(6,1),Tcoord(6,0),Tcoord(5,0)};;
public:

//-------------------
    Tboard() {
        for (int i=0; i<11; i++) {
            for (int j=0; j<11; j++){
                temporary_board[i][j]=' ';
            }
        }
        for(int i=0; i<40; i++) {
        temporary_board[play_fields[i].x][play_fields[i].y]='x';
        }
    }

    void print_yourself() {
            for (int i=0; i<11; i++) {
                for (int j=0; j<11; j++) {
                if(j==10) {
                cout<<temporary_board[i][j]<<endl;
                }
                else {
                cout<<temporary_board[i][j]<<" ";
                }
                }
            }
    }
};

int main()
{
Tboard screen;
screen.print_yourself();
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
