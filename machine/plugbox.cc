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

/*
** When the Plugbox is initialized, the "Panic" type of interrupt handling is entered for all interrupt numbers. 
*/
#include "machine/plugbox.h"

Plugbox::Plugbox()
{
    for (int i = 0; i < 64; i++)
    {
        IVT[i] = panic;
    }
}
/**
 *     Plug in a handler routine at the interrupt number slot, provided in the form of a Gate object.
 *     @param slot interrupt number slot
 *     @param gate Gate object to be plugged in
*/
void Plugbox::assign (unsigned int slot, Gate& gate){
    IVT[slot]=&gate;
}

/**
 *     Retrieve the Gate object for the specified slot.
 *     @param slot specified slot
*/
Gate& Plugbox::report (unsigned int slot){
    return *IVT[slot];
}


/* Add your code here */ 
