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

enum color {
red,
blue,
green,
yellow
    };

#endif // MAIN_H_INCLUDED
