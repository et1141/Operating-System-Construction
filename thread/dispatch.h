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

#ifndef __dispatch_include__
#define __dispatch_include__

#include "thread/coroutine.h"


class Dispatcher {
private:
	Coroutine *life;
public:
	Dispatcher(const Dispatcher &copy) = delete; // prevent copying

	/**
	 *     The constructor initializes the life pointer with null to indicate that no coroutine is known yet.
	 */
	Dispatcher();

	/**
	 *     With this method the coroutine first is put in the life pointer and started.
	 */
    void go(Coroutine &first);

	/**
	 *     This method sets the life pointer to next and performs a coroutine switch from the old to the new life pointer.
	 */
    void dispatch(Coroutine &next);


	/**
	 *     This can be used to determine which coroutine is currently in control of the processor.
	 */
    Coroutine *active();

};

#endif
