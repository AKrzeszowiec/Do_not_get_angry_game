#include "Tplayer.h"

Tplayer::Tplayer(){
    printw("Your name: ");
    echo();
    char temporary_name[21];
    getnstr(temporary_name,20);
    name=temporary_name;
    erase();
    noecho();

}

