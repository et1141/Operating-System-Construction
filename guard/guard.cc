/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

#include "guard/guard.h"
#include "user/globals.h"
#include "guard/secure.h"


void Guard::leave() {

    // Process accumulated epilogues
    while (!epilogue_queue.empty()) {
        cpu.disable_int(); //we don't want interrupt when we work with the queue
        Gate* gate = static_cast<Gate*>(epilogue_queue.dequeue());
        gate->queued(false);
        cpu.enable_int(); // we can be interrupted while we are executing the epilogue 
        gate->epilogue();
    }
    
}




void Guard::relay(Gate* item) {
    if (guard.avail()) {
        Secure section; // Enter critical section
        // If critical section is free, execute the epilogue immediately
        cpu.enable_int(); //Since in our implementation interrupts are disabled before guardian() is called, they must be enabled again "manually" 
        item->epilogue();
        guard.leave();
    } else {
        // If critical section is occupied, enqueue the epilogue
        if (!item->queued()) {
            item->queued(true);
            epilogue_queue.enqueue(item);
        }
        cpu.enable_int();
    }
}
