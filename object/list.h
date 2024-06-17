/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L I S T                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements a singly linked list of (meaningfully specialized) Chain       */
/* objects. In contrast to Queue, however, elements can also be inserted at  */
/* the beginning or in the middle.                                           */
/*****************************************************************************/

#ifndef __List_include__
#define __List_include__

#include "object/queue.h"

class List : public Queue {

public:
	List(const List &copy) = delete; // prevent copying

	// CONSTRUCTOR: The constructor initializes the list as empty.
	List() {}

	// FIRST: Returns the first element of the list without removing it.
	Chain *first() { return head; }

	// INSERT_FIRST: Inserts the new_item at the beginning of the list.
	void insert_first(Chain *new_item);

	// INSERT_AFTER: Inserts the new_item after the old_item element in the
	//               list.
	void insert_after(Chain *old_item, Chain *new_item);
};

#endif
