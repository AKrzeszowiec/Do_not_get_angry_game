#include "Tplayer.h"

Tplayer::Tplayer(){
    echo();
    mvprintw(15,0,"Your name: ");
    char temporary_name[21];
    bool isenter=false;
    int i=0;
    while(!isenter&&i<20) {

        char temp_char=getch();
        if (temp_char==10) {
            isenter=true;
            temporary_name[i]=NULL;
        }
        else if (temp_char>64&&temp_char<133){
            temporary_name[i]=temp_char;
            i++;
        }

    }
    temporary_name[20]=NULL;
    name=temporary_name;
    erase();
    noecho();

}

