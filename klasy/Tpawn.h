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
    Tpawn();


    color pawn_color;
    pawn_nr name;
    protected:
    private:

};

#endif // TPIONEK_H
