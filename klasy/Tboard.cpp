#include "Tboard.h"
#include <ncurses.h>


Tboard::Tboard(){
    for(int i=0;i<40;i++){ //fields_with_pawns keeps the informaton if there's a pawn (and which pawn) on a given field. We inicialize it with NULLS as no pawns are on the board
        fields_with_pawns[i]=NULL;
        }
    die=new Tdie();
    printw("How many players? Choose  2  3  4");
    int pressed_key=1;
    while(pressed_key!=50&&pressed_key!=51&&pressed_key!=52){ //we force the player to press 2,3 or 4
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
    for (int i=0;i<number_of_players;i++){//creating players
        printw("Player %d", i+1);
        move(1,0);
        players[i]=new Tplayer(this);
    }
}




void Tboard::print_yourself() {


    for (int i=0; i<40; i++) {//printing the board fields which aren't bases
        switch(i) //switch needed to print the starting fields in other color
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
    for (int i=0; i<4; i++){ //printing bases

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
    bool ending=false;
    int i=0; //will tell us which player turn it is
    while(!ending) {
        this->print_yourself(); //we start with printing the board and all the pawns anew, so that we can see their new positions
        for(int j=0;j<number_of_players;j++){
            for(int t=0;t<4;t++){
                players[j]->pawns[t]->print_yourself();
            }
        }
        i=i%number_of_players;
        int roll_result=die->roll_result();
        mvprintw(5,26,"%d",roll_result);
        Tpawn* temporary_pawn=players[i]->pawn_choosing(roll_result); //temporary pawn is the first pawn which can move
        if(temporary_pawn==NULL){ //if the pawn_choosing function retunrs NULL it means there was no possible movement
            mvprintw(20,0,"no possible movement!");
            getch();
        }
        else{
            bool allowed_movement=*temporary_pawn+roll_result; //we try moving the pawn and we check if it is a valid movement (ie one that doesn't kill our own pawn)
            while(!allowed_movement){ //the movement would kill our own pawn, so we force the player to choose another pawn until the movement is valid
                mvprintw(20,0,"Hey! You cannot kill your own pawn, can you?!");
                temporary_pawn->print_yourself();
                temporary_pawn=players[i]->pawn_choosing(roll_result);
                allowed_movement=*temporary_pawn+roll_result;
            }
            if(temporary_pawn->in_base){ //if the pawn ends up in the base, we pass the information to the player and increment the variable holding the information about pawns in the base
                players[i]->pawns_in_base=players[i]->pawns_in_base+1;
            }
                if(players[i]->pawns_in_base==4){ //if the player has four pawns in his base then the game ends
                    erase();
                    this->print_yourself(); //one more printing needed so that we truly can see the last pawn in the base
                    for(int j=0;j<number_of_players;j++){
                        for(int t=0;t<4;t++){
                            players[j]->pawns[t]->print_yourself();
                        }
                    }
                mvprintw(20,0,"%s wins!",players[i]->name);
                ending=true;
                getch();
            }
        }
        erase();
        i++;
    }

}
