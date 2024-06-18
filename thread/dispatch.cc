/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Dispatcher implementation.                                                */
/* The Dispatcher maintains the life pointer that points to the currently    */
/* active coroutine. go() initializes the life pointer and starts the first  */
/* coroutine, all further context switches are triggered by dispatch().      */
/* active() returns the life pointer.                                        */
/*****************************************************************************/

#include "thread/dispatch.h"

Dispatcher::Dispatcher() {
    life = nullptr;
}

void Dispatcher::go(Coroutine &first) {
    life = &first;
    life->go();
}

void Dispatcher::dispatch(Coroutine &next) {
    Coroutine *old = life;
    life = &next;
    old->resume(next);
}

Coroutine *Dispatcher::active() {
    return life;
}