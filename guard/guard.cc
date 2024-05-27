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


void Guard::leave() {
    Locker::retne(); // Leave the critical section

    // Process accumulated epilogues
    while (!epilogue_queue.empty()) {
        Gate* gate = static_cast<Gate*>(epilogue_queue.dequeue());
        gate->queued(false);
        gate->epilogue();
    }
}

void Guard::relay(Gate* item) {
    if (avail()) {
        // If critical section is free, execute the epilogue immediately
        item->epilogue();
    } else {
        // If critical section is occupied, enqueue the epilogue
        if (!item->queued()) {
            item->queued(true);
            epilogue_queue.enqueue(item);
        }
    }
}
