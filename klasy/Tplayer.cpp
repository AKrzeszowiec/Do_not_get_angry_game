#include "Tplayer.h"

Tplayer::Tplayer(Tboard *board){
    printw("Your name: ");
    echo();
    char temporary_name[21];
    char* printable_color;
    getnstr(temporary_name,20);
    name=temporary_name;
    mvprintw(2,10,"%s",name);
    erase();
    noecho();

// choosing the colour of the player
    int run_choosing_color=1;
    while(run_choosing_color){
        printw("%s choose your colour.",name);
        mvprintw(1,0,"Press 1 for red, 2 for blue, 3 for green and 4 for yellow.");
        int pressed_key=1;
        while(pressed_key!=50&&pressed_key!=51&&pressed_key!=52&&pressed_key!=49){
            noecho();
            pressed_key=getch();
        }
        switch(pressed_key)
        {
        case 49:
        player_color=red;
        printable_color="red";
        break;
        case 50:
        player_color=blue;
        printable_color="blue";
        break;
        case 51:
        player_color=green;
        printable_color="green";
        break;
        case 52:
        player_color=yellow;
        printable_color="yellow";
        }

        if((board->chosen_colors[player_color])==0){
            board->chosen_colors[player_color]=1;
            run_choosing_color=0;
            mvprintw(3,10,"%s",printable_color);
            getch();
            erase();
        }
        else {
            mvprintw(3,10,"already chosen! Choose other colour.");
            getch();
            erase();
        }
    }
}

