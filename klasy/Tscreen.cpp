#include "Tscreen.h"




Tscreen::Tscreen()
{
    initscr();
    curs_set(0);
    noecho();
    start_color();
    init_pair(green+1,COLOR_GREEN,COLOR_BLACK);
    init_pair(red+1,COLOR_RED,COLOR_BLACK);
    init_pair(blue+1,COLOR_BLUE,COLOR_BLACK);
    init_pair(yellow+1,COLOR_YELLOW,COLOR_BLACK);
    keypad(stdscr, true);
    Tboard board;
    board.print_yourself();
    for(int i=0;i<board.number_of_players;i++){
        for(int j=0; j<4; j++){
            board.players[i]->pawns[j]->print_yourself();
        }
    }
    this->keyboard_handling();

}

void Tscreen::keyboard_handling(){

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


