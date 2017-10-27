#include "Tpawn.h"

Tpawn::Tpawn(color pawn_color, pawn_nr name): pawn_color(pawn_color), name(name) {
    on_board=false;
    int position=pawn_color*10;
}

void Tpawn::print_yourself() {
    int x,y;
    Tcoord possible_start_locations[4]={Tcoord(0,0),Tcoord(0,2),Tcoord(1,0),Tcoord(1,2)};
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
        x+=possible_start_locations[name].x;
        y+=possible_start_locations[name].y;
        attron(COLOR_PAIR(pawn_color+1));
        mvprintw(x,y,"O");
        attroff(COLOR_PAIR(pawn_color+1));
    }
    else {

    }

}
