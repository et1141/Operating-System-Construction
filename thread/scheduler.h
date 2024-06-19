/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
/* Add your code here */ 

#include "thread/dispatch.h"
#include "thread/entrant.h"
#include "object/queue.h"

class Scheduler : public Dispatcher {
private:
    Queue ready_list;

public:
    Scheduler();

    void ready(Entrant& that);
    void schedule();
    void exit();
    void kill(Entrant& that);
    void resume();
	Scheduler (const Scheduler &copy) = delete; // prevent copying
};

#endif
