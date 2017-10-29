#include "Tpawn.h"

Tpawn::Tpawn(color pawn_color, pawn_nr name, Tboard *board): pawn_color(pawn_color), name(name), board(board) {
    on_board=false;
    start_position=pawn_color*10; //start position purely depends on the colour of the pawn
    fields_passed=0; //the pawn hasn't walked on any fields yet
    in_base=false;
    highlight=false;
}

void Tpawn::print_yourself() {
    int x,y;
    Tcoord wait_locations[4]={Tcoord(0,0),Tcoord(0,2),Tcoord(1,0),Tcoord(1,2)};
    if(!on_board){ //if the pawn isn't on board then we print it on its wait location
        switch (pawn_color)
        {
        case red:
        x=0;
        y=0;
        break;
        case yellow:
        x=9;
        y=0;
        break;
        case green:
        x=9;
        y=18;
        break;
        case blue:
        x=0;
        y=18;
        }
        x+=wait_locations[name].x;
        y+=wait_locations[name].y;

    }
    else {
        if(in_base){
            x=(*bases_list[pawn_color])[name].x;
            y=(*bases_list[pawn_color])[name].y;
        }
        else {
            x=play_fields[(start_position+fields_passed)%40].x;
            y=play_fields[(start_position+fields_passed)%40].y;
        }
    }
        attron(COLOR_PAIR(pawn_color+1)); //we choose appropriate colour for printing
        if (this->highlight){ //if the pawn is highlighted then we print it out in bold
            attron(A_BOLD);
            mvprintw(x,y,"O");
            attroff(A_BOLD);
        }
        else {
            mvprintw(x,y,"O");
        }
        attroff(COLOR_PAIR(pawn_color+1));

}


bool Tpawn::operator+(int digit){
    bool allowed_movement; //if the pawn doesn't kill our own pawn, that's the value which we will return
    if(this->on_board){ //in chase the pawn is on the board
        if (fields_passed+digit>39){ //it means the pawn will end up in base
            board->fields_with_pawns[(start_position+fields_passed)%40]=NULL; //the pawn isn't on the previous field anymore so we mark it by putting NULL there
            this->in_base=true;
            allowed_movement=true;
        }
        else {

            if(board->fields_with_pawns[(start_position+fields_passed+digit)%40]!=NULL){ //in this case there's a pawn on the field which the pawn is about to move onto
                if(board->fields_with_pawns[(start_position+fields_passed+digit)%40]->pawn_color==this->pawn_color) //if the pawn is the same coulour, then we don't allow it to happen and we return false
                {
                    allowed_movement=false;
                }
                else{ //if it's not our pawn then we go ahead and kill it, yeah!
                    (board->fields_with_pawns[(start_position+fields_passed+digit)%40])->kill_yourself(); //killing the pawn
                    board->fields_with_pawns[(start_position+fields_passed)%40]=NULL; //deleting info about our prevous position
                    fields_passed=(fields_passed+digit); //moving
                    board->fields_with_pawns[(start_position+fields_passed)%40]=this; //marking our new position
                    allowed_movement=true;
                }
            }
            else{ //if the field we're about to move onto is empty, then we just move
                board->fields_with_pawns[(start_position+fields_passed)%40]=NULL;
                fields_passed=(fields_passed+digit);
                board->fields_with_pawns[(start_position+fields_passed)%40]=this;
                allowed_movement=true;
            }
        }
    }
    else { //if the pawn wasn't on the board yet
        if(board->fields_with_pawns[start_position]!=NULL){//again checking if there's something on the field we're about to step onto
            if(board->fields_with_pawns[start_position]->pawn_color==pawn_color){//yep, our pawn, so we don't move
                allowed_movement=false;
                }

            else{ //yep, but not our pawn, so we kill it!!
                board->fields_with_pawns[start_position]->kill_yourself();
                board->fields_with_pawns[start_position]=this;
                on_board=true;
                allowed_movement=true;
            }
        }
        else{ //there's nothing so we just move
            board->fields_with_pawns[start_position]=this;
            on_board=true;
            allowed_movement=true;
        }
    }
    return allowed_movement;
}

void Tpawn::kill_yourself(){ //when the pawn gets killd it isn't on the board anymore and has to start its journey anew
    on_board=false;
    fields_passed=0;
}
