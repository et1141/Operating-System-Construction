/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The system's central interrupt handling routine.                          */
/* The parameter specifies the number of the interrupt that occurred.        */
/*****************************************************************************/

/* INCLUDES */
#include "device/cgastr.h"
#include "user/appl.h"


/* FUNCTIONS */

extern "C" void guardian (unsigned int slot);
/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot)
{
    switch(slot){
    case 0:
        kout.print("timer",5,5);
        break;
    case 1:
        kout.print("keyboard",8,5);
        break;
    default:
        kout.print("unknown",7,5);
        break;   
    } 
}

