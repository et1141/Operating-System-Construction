/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/
#include "pit.h"

void PIT::initialize(int us) {
    set_timer(us);
}

int PIT::interval() const {
    return current_interval;
}

void PIT::interval(int us) {
    set_timer(us);
}