#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
class Tplayer;
class Tpawn;
class Tscreen;
class Tboard;
class Tdie;

class Tcoord {
public:
    int x;
    int y;
    Tcoord(int x, int y) : x(x), y(y) {}
};

extern const Tcoord play_fields[40];
extern const Tcoord green_base[4];
extern const Tcoord red_base[4];
extern const Tcoord blue_base[4];
extern const Tcoord yellow_base[4];
extern const Tcoord (*bases_list[4])[4];


enum color {
red,
blue,
green,
yellow
    };

#endif // MAIN_H_INCLUDED
