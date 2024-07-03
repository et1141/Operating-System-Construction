/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Handles timer interrupts by managing a time slice and triggering a        */
/* process switch if necessary.                                              */
/*****************************************************************************/

#include "device/watch.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_scheduler.h"
#include "user/globals.h"

Watch::Watch(int us) : PIT(us) {
    // Initialize the PIT with the given interval
}

void Watch::windup() {
    // Register the Watch object with the Plugbox
    plugbox.assign(plugbox.timer, *this);

    // Allow timer interrupts using the PIC
    pic.allow(pic.timer);
}

bool Watch::prologue() {
    return true;
}

void Watch::epilogue() {
    // Trigger the process switch
    scheduler.resume();
}