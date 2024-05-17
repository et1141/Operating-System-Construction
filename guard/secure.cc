#include "guard/secure.h"
#include "user/globals.h"



/**
 *   In the constructor, the critical section protected by the Guard object guard is entered. 
*/ 
Secure::Secure (){
    guard.enter();
}

/**
 * In the destructor, the critical section is exited. 
*/
Secure::~Secure (){
    guard.avail();
}