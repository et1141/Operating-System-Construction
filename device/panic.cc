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
#include "device/cgastr.h"
 
extern CGA_Stream kout;

void Panic::trigger()
{
    kout << "Panic::trigger() called" << endl; //Correct ?

    while (1)
    {
    }
}