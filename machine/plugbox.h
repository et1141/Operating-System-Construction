/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstracts an interrupt vector table. Allows to configure handler routines */
/* for every hardware and software interrupt and every CPU exception.        */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"

class Plugbox {
public:

	static const int timer = 32; //    Interrupt number of the timer module
	static const int keyboard = 33; //	    Interrupt number of the keyboard

	Plugbox();
	Plugbox(const Plugbox &copy) = delete; // prevent copying
	void assign (unsigned int slot, Gate& gate);
	Gate& report (unsigned int slot);

private:
	Gate * IVT[64];  // interrupt vector table
};

#endif
