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

#include "watch.h"
#include "plugbox.h"
#include "pic.h"
#include "guarded_scheduler.h"
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
    // Prologue of the interrupt handler
    // Handle the beginning of the interrupt
    // For simplicity, always return true to indicate that the epilogue should be called
    return true;
}

void Watch::epilogue() {
    // Trigger the process switch
    scheduler.resume();
}