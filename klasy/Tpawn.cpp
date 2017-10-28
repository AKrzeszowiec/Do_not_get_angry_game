#include "Tpawn.h"

Tpawn::Tpawn(color pawn_color, pawn_nr name): pawn_color(pawn_color), name(name) {
    on_board=false;
    start_position=pawn_color*10;
    fields_passed=0;
    in_base=false;
    highlight=false;
}

void Tpawn::print_yourself() {
    int x,y;
    Tcoord wait_locations[4]={Tcoord(0,0),Tcoord(0,2),Tcoord(1,0),Tcoord(1,2)};
    if(!on_board){
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
        attron(COLOR_PAIR(pawn_color+1));
        if (this->highlight){
            attron(A_BOLD);
            mvprintw(x,y,"O");
            attroff(A_BOLD);
        }
        else {
            mvprintw(x,y,"O");
        }
        attroff(COLOR_PAIR(pawn_color+1));

}


Tpawn Tpawn::operator+(int digit){
    if(this->on_board){
        if (fields_passed+digit>39){
            this->in_base=true;
        }
        else {
            fields_passed=(fields_passed+digit);
        }
    }
    else {
        on_board=true;
    }
    return *this;
}
