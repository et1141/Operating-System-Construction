/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The toc struct is used to save the values of the non-volatile registers   */
/* in case of a context switch. toc_settle prepares the initial stack and    */
/* the toc struct for the first activation.                                  */
/*****************************************************************************/
#include <stdio.h>
#include "machine/toc.h"
#include <stdint.h>

/**
 * Prepares a coroutine context for its first activation.
*/
void toc_settle(struct toc *regs, void *tos,
		void (*kickoff)(void *, void *, void *, void *, void *, void *,
				void *),
		void *object)
{
	regs->rbx = NULL;
	regs->r12 = NULL;
	regs->r13 = NULL;
	regs->r14 = NULL;
	regs->r15 = NULL;
	regs->rbp = NULL;


 
    void ** stack = (void **)tos;

	//adresses are 2 bytes long
	stack-=1;
	*(stack) = object;
    
    stack-=2;
	*(stack) = kickoff; 

    regs->rsp = (void *)stack;

}


/* Notes:

General schema for coroutine activation:

extern "C" void resume( SP& from_sp, SP& to_sp ) {
	// current stack frame is the continuation of the
	//to-be-suspended control flow (caller of resume) 
	< push non-volatile registers on the stack >
	< save CPU stack pointer in from_sp >
	< load CPU stack pointer from to_sp >
	< pop non-volatile registers from the stack >
	//current stack frame is the continuation of the
	//to-be-(re)activated control flow 
} // return

*/