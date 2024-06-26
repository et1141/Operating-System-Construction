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

#ifndef __Guard_include__
#define __Guard_include__

#include "object/queue.h"
#include "guard/locker.h"
#include "guard/gate.h"


class Guard : public Locker {
private:
    Queue epilogue_queue;

public:
	Queue queue;
	Guard (const Guard &copy) = delete; // prevent copying
	Guard () {}

    /**
     * Method to leave the critical section. Accumulated epilogues can be processed now.
     */
    void leave();

    /**
     * Method to relay epilogue execution. If the critical section is occupied, the epilogue is queued.
     * @param item Pointer to the Gate object whose epilogue should be executed.
     */
    void relay(Gate* item);

};

#endif
