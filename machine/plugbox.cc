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

#include "machine/plugbox.h"
#include "device/panic.h"

Panic panic;

/**
 * In the constructor, the global known Panic object panic is registered for all interrupts and exceptions, which provides a minimal interrupt handling.
*/
Plugbox::Plugbox()
{
    for (int i = 0; i < 64; i++)
    {
        IVT[i] = &panic; // register panic for all interrupts
    }
}

/**
 * Plug in a handler routine at the interrupt number slot, provided in the form of a Gate object.
 * @param slot interrupt number slot
 * @param gate Gate object to be plugged in
*/
void Plugbox::assign (unsigned int slot, Gate& gate){
    IVT[slot]=&gate;
}

/**
 * Retrieve the Gate object for the specified slot.
 * @param slot requested interrupt number slot 
*/
Gate& Plugbox::report (unsigned int slot){
    return *IVT[slot];
}

