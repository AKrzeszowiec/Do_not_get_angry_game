#include "Tscreen.h"




Tscreen::Tscreen()
{
    initscr(); //ncurses stuff needed to initialize the screen
    curs_set(0); //making the cursor disappear
    noecho();
    start_color(); //we'll wabt to use colour for sure, so we initialize some colours
    init_pair(green+1,COLOR_GREEN,COLOR_BLACK);
    init_pair(red+1,COLOR_RED,COLOR_BLACK);
    init_pair(blue+1,COLOR_BLUE,COLOR_BLACK);
    init_pair(yellow+1,COLOR_YELLOW,COLOR_BLACK);
    keypad(stdscr, true);
    Tboard board; //we generate a new board, which in turn will initialize players and pawns
    board.player_choosing(); //the function used to jump between players and let them play their turns
    endwin();

}
