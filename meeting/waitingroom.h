/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements a list of processes (Customer objects) that are all waiting    */
/* for a specific event.                                                     */
/*****************************************************************************/

#ifndef __waitingroom_include__
#define __waitingroom_include__

#include "object/queue.h"
#include "thread/customer.h"

class Customer; // Forward declaration

class Waitingroom : public Queue {
public:
	Waitingroom(const Waitingroom &copy) = delete; // prevent copying
	Waitingroom() {}
/* Add your code here */ 
};

#endif
