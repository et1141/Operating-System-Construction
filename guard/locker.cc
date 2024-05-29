
#include "guard/locker.h"


extern "C" void guardian(unsigned int slot);



void Locker::enter(){
    if(free)
        guardian(42);
    else
        free=false;
}
void Locker::retne (){
    if(!free)
        guardian(42);
    else 
        free=true;
}