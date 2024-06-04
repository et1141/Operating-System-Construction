/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Represents the abstraction of a coroutine.                                */
/* In the constructor, we set up the initial context of the coroutine. go()  */
/* activates the first coroutine. All further coroutine switches should be   */
/* initiated by resume().                                                    */
/* To be able to save the context at a couroutine switch, every Coroutine    */
/* object contains a struct toc that stores the values of all non-volatile   */
/* registers.                                                                */
/*****************************************************************************/

#ifndef __Coroutine_include__
#define __Coroutine_include__

#include "machine/toc.h"

class Coroutine {
private:
	toc register_contents; // Values of non-volatile registers
public:
	Coroutine(const Coroutine &copy) = delete; // prevent copying
	/**
	 * Initialize values so that the stack pointer initially points to tos and on first activation execution begins with the kickoff function.
	*/
	Coroutine (void* tos);
	/**
	 * This method is used for the first activation of the first coroutine in the system. Therefore no register values must be saved here.
	*/
	void go(); // First activation
	/**
	 * This method triggers a coroutine switch. The current contents of the non-volatile registers are saved in the toc element and replaced by the values of next (the toc element of the next coroutine).
	*/
    void resume(Coroutine& next); // Coroutine switch
	/**
	 * The method action represents the actual job of the coroutine. However, since not all coroutines in the system should do the same, action can only be defined in a specialized class (e.g. in Application).
	*/
    virtual void action() = 0; 
};

#endif
