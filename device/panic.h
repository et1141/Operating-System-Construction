/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */

#include "guard/gate.h"


class Panic: public Gate

{
public:
	Panic (const Panic &copy) = delete; // prevent copying
	Panic () {}
    void trigger ();

 
};

#endif
