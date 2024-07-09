/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#include <thread/scheduler.h>
#include "user/globals.h"
#include "guard/secure.h"


Scheduler::Scheduler() : Dispatcher() {
    // Initialization if needed
}

void Scheduler::ready(Entrant& that) {
    ready_list.enqueue(&that);
}

void Scheduler::schedule() {
    if (!ready_list.empty()) {
        Entrant* next = static_cast<Entrant*>(ready_list.dequeue());
        go(*next);
    }
}

void Scheduler::exit() {
    // Remove the current process and schedule the next one
    if (!ready_list.empty()) {
        Entrant* current = static_cast<Entrant*>(ready_list.dequeue());
        // Do not re-queue the current coroutine
        if (current) {
            dispatch(*current);
        }
    }
}

void Scheduler::kill(Entrant& that) {
    //add edge case when process calling kill to itself
    ready_list.remove(&that);
    delete &that; // Clean up the memory
    Entrant* current = static_cast<Entrant*>(ready_list.dequeue());
    //Entrant* current_coroutine_casted = static_cast<Coroutine*>(current);
    dispatch(*current);

    
}

void Scheduler::resume() {
    // Save the currently running process and schedule the next one
    Entrant* current = static_cast<Entrant*>(ready_list.dequeue());
    if (current) {                
        ready_list.enqueue(static_cast<Entrant*>(active()));
        dispatch(*current);
    }
}