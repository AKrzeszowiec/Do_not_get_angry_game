#ifndef TPAWN_H
#define TPAWN_H
#include "Tboard.h"
#include "../main.h"

enum pawn_nr {
    pawn0,
    pawn1,
    pawn2,
    pawn3
    };

class Tpawn
{
    public:
    color pawn_color;
    pawn_nr name;
    Tboard *board;
    bool highlight;
    bool on_board;
    int start_position;
    int fields_passed;
    bool in_base;


    Tpawn(color pawn_color, pawn_nr name, Tboard* board);
    void print_yourself();
    bool operator+(int digit);
    void kill_yourself();
    protected:
    private:

};

#endif // TPIONEK_H
