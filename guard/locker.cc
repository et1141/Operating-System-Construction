
#include "guard/locker.h"


extern "C" void guardian(unsigned int slot);



void Locker::enter(){
    if(!_is_free)
        guardian(42);
    else
        _is_free=false;
}

void Locker::retne (){
    if(_is_free)
        guardian(42);
    else 
        _is_free=true;
}

 bool Locker::avail() const {
        return _is_free;
    }