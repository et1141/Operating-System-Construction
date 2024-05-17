/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              C H A I N                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* By inheriting from the Chain class, the derived class inherits a chain    */
/* pointer that allows its instances to be enqueued in a linked list         */
/* (implemented in the Queue class).                                         */
/*****************************************************************************/

#ifndef __chain_include__
#define __chain_include__

class Chain {

public:
	Chain(const Chain &copy) = delete; // prevent copying
	Chain() {}
	Chain *next;
};

#endif
