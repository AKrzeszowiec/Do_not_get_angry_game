#ifndef TPLAYER_H
#define TPLAYER_H
#include "ncurses.h"
#include "../main.h"
#include "Tboard.h"
#include "Tpawn.h"

class Tboard;
class Tpawn;

class Tplayer
{
    public:
        Tplayer(Tboard *whichboard);
        char name[21];
        color player_color;
    protected:
    private:
};

#endif // TPLAYER_H
