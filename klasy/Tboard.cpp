#include "Tboard.h"
#include <ncurses.h>

void Tboard::print_yourself() {
    initscr();
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(3,COLOR_BLUE,COLOR_BLACK);
    init_pair(4,COLOR_YELLOW,COLOR_BLACK);
    for (int i=0; i<40; i++) {
        switch(i)
        {
        case 0:
        attron(COLOR_PAIR(2));
        break;
        case 10:
        attron(COLOR_PAIR(3));
        break;
        case 20:
        attron(COLOR_PAIR(1));
        break;
        case 30:
        attron(COLOR_PAIR(4));
        break;
        }
        mvaddch(play_fields[i].x,play_fields[i].y,'x');
        switch(i)
        {
        case 0:
        attroff(COLOR_PAIR(2));
        break;
        case 10:
        attroff(COLOR_PAIR(3));
        break;
        case 20:
        attroff(COLOR_PAIR(1));
        break;
        case 30:
        attroff(COLOR_PAIR(4));
        break;
        }

    }
    for (int i=0; i<4; i++){

        attron(COLOR_PAIR(1));
        mvaddch(green_base[i].x,green_base[i].y,'o');
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        mvaddch(red_base[i].x,red_base[i].y,'o');
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(3));
        mvaddch(blue_base[i].x,blue_base[i].y,'o');
        attroff(COLOR_PAIR(3));
        attron(COLOR_PAIR(4));
        mvaddch(yellow_base[i].x,yellow_base[i].y,'o');
        attroff(COLOR_PAIR(4));
    }
}
