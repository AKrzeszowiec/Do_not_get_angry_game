#include "Tdie.h"
#include "cstdlib"
Tdie::Tdie(int max_value): max_value(max_value){ }

int Tdie::roll_result(){
    int result=(rand()%6)+1;
    return result;
}


