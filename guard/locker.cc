
#include "guard/locker.h"
#include "user/globals.h"


extern "C" void guardian(unsigned int slot);



void Locker::enter(){
    if(!_is_free)
        kout<<"ENTERING  CRITICAL SECTION TWICE!\n";
       // guardian(42);
    else
        _is_free=false;
}

void Locker::retne (){
    if(_is_free)
        kout<<"LEAVING CRITICAL SECTION TWICE!\n";
    else 
        _is_free=true;
}

 bool Locker::avail() const {
        return _is_free;
    }