#include "Tpawn.h"

Tpawn::Tpawn(color pawn_color, pawn_nr name): pawn_color(pawn_color), name(name) {
    on_board: false;
    int position=pawn_color*10;
}
