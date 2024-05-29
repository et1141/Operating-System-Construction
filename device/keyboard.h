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
#include "machine/key.h"
class Keyboard: public Gate, public Keyboard_Controller
{
private:
    Key key;
public:
	Keyboard(const Keyboard &copy) = delete; // prevent copying
	Keyboard(); 

	void plugin();
	Keyboard_Controller keyboard_controller; // shoud i=be private? (test_keyboard_controller is using the object, so when make private it will have to define another Keyboard_Controller object)

	/**
     * This method responds to interrupts from the keyboard. 
     * @return true if the epilogue should be executed, false otherwise.
     */
    bool prologue() override;

    /**
     * Here, the character that was read during the prologue handling is displayed on the screen.
     */
    void epilogue() override;

    void trigger();
};

#endif
