/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements user interface of a thread.                                    */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

/* Add your code here */ 
 #include "thread/entrant.h"
class Thread : public Entrant {
public:
    // Constructor that initializes the Thread with a top-of-stack pointer
	Thread(const Thread &copy) = delete; // prevent copying
    Thread(void* tos) : Entrant(tos) {}
};

#endif
