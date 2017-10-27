#ifndef TPLAYER_H
#define TPLAYER_H
#include "ncurses.h"
#include "../main.h"
#include "Tboard.h"

class Tboard;

class Tplayer
{
    public:
        Tplayer(Tboard *whichboard);
        char* name;
        color player_color;
    protected:
    private:
};

#endif // TPLAYER_H
