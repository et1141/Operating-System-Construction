/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#include "device/panic.h"
#include "user/globals.h"


/**
 * Default interrupt handler. Called when an interrupt without a handler is triggered. Prints something and stops CPU.
*/
void Panic::trigger(){
    kout.print("panic_interrupt_handling",25,5);
    cpu.halt();
}