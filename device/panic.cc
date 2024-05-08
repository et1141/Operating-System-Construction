/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/
/* Add your code here */ 
/* Add your code here */ 
 

#include "device/panic.h"
#include "user/appl.h"
#include "machine/cpu.h"

void trigger(){
    kout.print("panic_interrupt_handling",25,5);
    cpu.halt();

}