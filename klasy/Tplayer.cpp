#include "Tplayer.h"


Tplayer::Tplayer(Tboard *board): board(board){
    pawns_in_base=0;
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
        while(pressed_key!=50&&pressed_key!=51&&pressed_key!=52&&pressed_key!=49){//we force the player to press 1,2,3 or 4
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

        if((board->chosen_colors[player_color])==0){ //checking if the colour has been already chosen
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
        pawns[i]=new Tpawn(player_color,static_cast<pawn_nr>(i),board);//we generate 4 pawns belonging to the player
    }
}


//choosing the pawn to play it, depending on the die roll result
Tpawn* Tplayer::pawn_choosing(int roll_result) {
    Tpawn* temporary_pawn;
    bool is_six=false; //function behaves differently if the result is 6
    bool exists_playable_pawn=false;
    if(roll_result==6){
        is_six=true;
    }

    int which_pawn=0;
    if(!is_six){ //if we don't have a six on the die then we have to check if there exists a pawn which is on the board and not in a base
        for(int i=0;i<4;i++){
            if(pawns[i]->on_board&&!pawns[i]->in_base){
                exists_playable_pawn=true;
            }
        }
    }
    if(is_six||exists_playable_pawn){ //in this case there exists a pawn which we can play, so we process to choosing it
        while((!is_six&&!pawns[which_pawn]->on_board)||pawns[which_pawn]->in_base){//searching for a pown which isn't in the base and which either is on the board or we have six on the die.
            which_pawn++;
        }
        temporary_pawn=pawns[which_pawn];
        temporary_pawn->highlight=true;
        temporary_pawn->print_yourself();
        temporary_pawn->highlight=false;
        bool ending=false;
        while(!ending){
            int c=getch();
            switch(c)
            {
            case 260: //left arrow
                do{
                which_pawn=which_pawn-1;
                if(which_pawn<0){which_pawn=3;}
                }while((!is_six&&!pawns[which_pawn]->on_board)||pawns[which_pawn]->in_base);//again, searching for a pown which isn't in the base and which either is on the board or we have six on the die.
                break;
            case 261: //right arrow
                do{
                which_pawn=(which_pawn+1)%4;
                }while((!is_six&&!pawns[which_pawn]->on_board)||pawns[which_pawn]->in_base);//same as above
                break;
            case 10: //enter
                ending=true;
                break;
            }
            temporary_pawn->print_yourself();//we want the temporary pawn to stop being highlighted and then we highlight the new one
            temporary_pawn=pawns[which_pawn];
            temporary_pawn->highlight=true;
            temporary_pawn->print_yourself();
            temporary_pawn->highlight=false;
        }

    }
    else{ //if there doesn't exist a playable pawn, then we return NULL
        temporary_pawn=NULL;
    }
    return temporary_pawn;
}
