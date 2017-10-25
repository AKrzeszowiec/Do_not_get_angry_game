#ifndef TSCREEN_H
#define TSCREEN_H
#include "Tboard.h"
#include "Tplayer.h"
#include "ncurses.h"
#include <string>

using namespace std;

class Tscreen
{
    public:
        Tscreen();
    protected:
    private:
    void keyboard_handling();
};

#endif // TSCREEN_H
