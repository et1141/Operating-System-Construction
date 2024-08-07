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
#include "user/globals.h"

/* FUNCTIONS */

extern "C" void guardian (unsigned int slot);


/**
 * The guardian function is responsible for device-specific interrupt handling. For this purpose the corresponding Gate object is determined with the help of the interrupt number in the global Plugbox object plugbox and its trigger() method is executed. 
 * @param slot interrupt numer. Firs 32 are reserved for CPU exceptions, the rest for hardware and software interrupts. Eg: 0 is the CPU exception for division by zero, 32 is the hardware interrupt for the timer, 33 is keyboard interrupt.
*/
void guardian(unsigned int slot) {    
       if (slot ==plugbox.timer){

        // Find the corresponding Gate object using the interrupt number
        Gate& gate = plugbox.report(slot);
        
        // Execute the prologue method of the Gate object
        bool request_epilogue = gate.prologue();
        
        // If the prologue indicates that an epilogue is necessary, relay it
        if (request_epilogue) {
            guard.relay(&gate);
        }
    }
    else if(slot==42){
            kout.print("ENTERING OR LEAVING CRITICAL SECTION TWICE!",44,5);
        } 
}
