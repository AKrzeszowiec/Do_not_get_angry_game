#ifndef TBOARD_H
#define TBOARD_H
#include "Tplayer.h"
#include "Tpawn.h"
#include "../main.h"
#include "Tdie.h"



//class Tcoord;

class Tboard
{
public:
    Tboard();
    int number_of_players;
    void print_yourself();
    int chosen_colors[4]={0,0,0,0};
    Tplayer* players[4];
    Tdie* die;
    Tpawn* fields_with_pawns[40];

    void player_choosing();

};

#endif // TBOARD_H
