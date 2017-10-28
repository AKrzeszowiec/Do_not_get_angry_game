#include "Tboard.h"
#include <ncurses.h>


Tboard::Tboard(){
    //int dupa=getch();
    //printw("%d", dupa);
    //getch();
    die=new Tdie();
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
    for (int i=0;i<number_of_players;i++){
    printw("Player %d", i+1);
    move(1,0);
    players[i]=new Tplayer(this);
    }
}




void Tboard::print_yourself() {


    for (int i=0; i<40; i++) {
        switch(i)
        {
        case 0:
        attron(COLOR_PAIR(red+1));
        break;
        case 10:
        attron(COLOR_PAIR(blue+1));
        break;
        case 20:
        attron(COLOR_PAIR(green+1));
        break;
        case 30:
        attron(COLOR_PAIR(yellow+1));
        break;
        }
        mvaddch(play_fields[i].x,play_fields[i].y,'x');
        switch(i)
        {
        case 0:
        attroff(COLOR_PAIR(red+1));
        break;
        case 10:
        attroff(COLOR_PAIR(blue+1));
        break;
        case 20:
        attroff(COLOR_PAIR(green+1));
        break;
        case 30:
        attroff(COLOR_PAIR(yellow+1));
        break;
        }

    }
    for (int i=0; i<4; i++){

        attron(COLOR_PAIR(green+1));
        mvaddch(green_base[i].x,green_base[i].y,'o');
        attroff(COLOR_PAIR(green+1));
        attron(COLOR_PAIR(red+1));
        mvaddch(red_base[i].x,red_base[i].y,'o');
        attroff(COLOR_PAIR(red+1));
        attron(COLOR_PAIR(blue+1));
        mvaddch(blue_base[i].x,blue_base[i].y,'o');
        attroff(COLOR_PAIR(blue+blue));
        attron(COLOR_PAIR(yellow+1));
        mvaddch(yellow_base[i].x,yellow_base[i].y,'o');
        attroff(COLOR_PAIR(yellow+1));
    }
}


void Tboard::player_choosing(){
    for(int i=0;;i++) {
        i=i%number_of_players;
        int roll_result=die->roll_result();
        mvprintw(5,26,"%d",roll_result);
        Tpawn* temporary_pawn=players[i]->pawn_choosing();

    }

}
