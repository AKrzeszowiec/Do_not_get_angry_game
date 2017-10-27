#ifndef TBOARD_H
#define TBOARD_H
#include "Tplayer.h"
#include "Tpawn.h"
#include "../main.h"

class Tcoord {
public:
    int x;
    int y;
    Tcoord(int x, int y) : x(x), y(y) {}
};

class Tboard
{
public:
    Tboard();
    int number_of_players;
    void print_yourself();
    int chosen_colors[4]={0,0,0,0};
private:
    const Tcoord play_fields[40]={Tcoord(4,0),Tcoord(4,2),Tcoord(4,4),Tcoord(4,6),Tcoord(4,8),Tcoord(3,8),Tcoord(2,8),Tcoord(1,8),Tcoord(0,8),Tcoord(0,10),Tcoord(0,12),Tcoord(1,12),Tcoord(2,12),Tcoord(3,12),Tcoord(4,12),Tcoord(4,14),Tcoord(4,16),Tcoord(4,18),Tcoord(4,20),Tcoord(5,20),Tcoord(6,20),Tcoord(6,18),Tcoord(6,16),Tcoord(6,14),Tcoord(6,12),Tcoord(7,12),Tcoord(8,12),Tcoord(9,12),Tcoord(10,12),Tcoord(10,10),Tcoord(10,8),Tcoord(9,8),Tcoord(8,8),Tcoord(7,8),Tcoord(6,8),Tcoord(6,6),Tcoord(6,4),Tcoord(6,2),Tcoord(6,0),Tcoord(5,0)};;
    const Tcoord green_base[4]={Tcoord(5,18),Tcoord(5,16),Tcoord(5,14),Tcoord(5,12)};
    const Tcoord red_base[4]={Tcoord(5,2),Tcoord(5,4),Tcoord(5,6),Tcoord(5,8)};
    const Tcoord blue_base[4]={Tcoord(1,10),Tcoord(2,10),Tcoord(3,10),Tcoord(4,10)};
    const Tcoord yellow_base[4]={Tcoord(9,10),Tcoord(8,10),Tcoord(7,10),Tcoord(6,10)};

};

#endif // TBOARD_H
