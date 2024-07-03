/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements the system-call interface to the Scheduler.                    */
/*****************************************************************************/
#include "syscall/guarded_scheduler.h"
#include "guard/secure.h"

void Guarded_Scheduler::ready(Thread& that) {
    Secure secure; // Enter critical section
    Scheduler::ready(that); // Call base class method
}

void Guarded_Scheduler::exit() {
    Secure secure; // Enter critical section
    Scheduler::exit(); // Call base class method
}

void Guarded_Scheduler::kill(Thread& that) {
    Secure secure; // Enter critical section
    Scheduler::kill(that); // Call base class method
}

void Guarded_Scheduler::resume() {
    Secure secure; // Enter critical section
    Scheduler::resume(); // Call base class method
}
