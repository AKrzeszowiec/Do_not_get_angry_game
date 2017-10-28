#ifndef TPLAYER_H
#define TPLAYER_H
#include "ncurses.h"
#include "../main.h"
#include "Tboard.h"
#include "Tpawn.h"
#include <cstring>
#include <string>



class Tplayer
{
    public:
        Tplayer(Tboard *whichboard);
        char name[21];
        color player_color;
        Tpawn* pawns[4];
        Tpawn* pawn_choosing(int roll_result);
    protected:
    private:
};

#endif // TPLAYER_H
