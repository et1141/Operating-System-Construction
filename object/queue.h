/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Q U E U E                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementation of a singly-linked list of Chain objects. enqueue()        */
/* inserts a new element at the end of the list, dequeue() removes the first */
/* element, and remove() remove the element indicated by its argument.       */
/* Initially, the queue is empty.                                            */
/*****************************************************************************/

#ifndef __queue_include__
#define __queue_include__

#include "object/chain.h"

class Queue {

protected:
	Chain *head;
	Chain **tail;

public:
	Queue(const Queue &copy) = delete; // prevent copying

	Queue()
	{
		head = 0;
		tail = &head;
	}
	void enqueue(Chain *item);
	Chain *dequeue();
	void remove(Chain *);
};

#endif
