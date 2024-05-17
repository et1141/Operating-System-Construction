
#include "guard/locker.h"


extern "C" void guardian(unsigned int slot);



void Locker::enter(){
    if(lock)
        guardian(42);
    else
        lock=true;
}
void Locker::retne (){
    if(!lock)
        guardian(42);
    else 
        lock=false;
}