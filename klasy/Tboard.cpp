#include "Tboard.h"
#include <ncurses.h>


Tboard::Tboard(){
    //int dupa=getch();
    //printw("%d", dupa);
    //getch();
    printw("How many players? Choose  2  3  4");

    int pressed_key=1;
    while(pressed_key!=50&&pressed_key!=51&&pressed_key!=52){
    noecho();
    pressed_key=getch();
    }
    switch(pressed_key)
    {
    case 50:
    number_of_players=2;
    break;
    case 51:
    number_of_players=3;
    break;
    case 52:
    number_of_players=4;
    }
    mvprintw(2,10,"%d",number_of_players);
    mvprintw(4,0,"press any key to continue...");
    getch();
    erase();
    Tplayer* players[number_of_players];
    for (int i=0;i<number_of_players;i++){
    printw("Player %d", i+1);
    move(1,0);
    players[i]=new Tplayer();
    }

    getch();
    erase();
}

// 2 - 50



void Tboard::print_yourself() {

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
