#include "Tplayer.h"


Tplayer::Tplayer(Tboard *board){
    printw("Your name: ");
    echo();
    getnstr(name,20);
    mvprintw(2,10,"%s",name);
    erase();
    noecho();

// choosing the colour of the player
    std::string printable_color;
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
            const char* cstr=printable_color.c_str();
            mvprintw(3,10,"%s",cstr);
            getch();
            erase();
        }
        else {
            mvprintw(3,10,"already chosen! Choose other colour.");
            getch();
            erase();
        }
    }
    for(int i=0; i<4; i++) {
        pawns[i]=new Tpawn(player_color,static_cast<pawn_nr>(i));
    }
}

Tpawn* Tplayer::pawn_choosing() {
    bool ending=false;
    Tpawn* temporary_pawn=pawns[0];
    temporary_pawn->highlight=true;
    temporary_pawn->print_yourself();
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
        case 10: //enter
            ending=true;
            break;
        }
    }

}
