/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h" 

class Keyboard: public Gate, public Keyboard_Controller
{
public:
	Keyboard(const Keyboard &copy) = delete; // prevent copying
	Keyboard(); 
 
	void plugin();
	void trigger ();
	Keyboard_Controller keyboard_controller; // shoud i=be private? (test_keyboard_controller is using the object, so when make private it will have to define another Keyboard_Controller object)

};

#endif
