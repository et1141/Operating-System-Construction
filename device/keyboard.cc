/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#include "keyboard.h"
#include "appl.h"

void Keyboard::plugin() {
    
}

// Responds to interrupts from the keyboard.
// If a valid key is detected, the ASCII code is displayed on the screen.
// If Ctrl-Alt-Delete is pressed, the system reboots.
void Keyboard::trigger() {
    Key pressed_key = key_hit();

    if (pressed_key.valid()) {
        // Display ASCII code on the screen
        kout.print((char*)pressed_key.ascii(), 1 , 6);
        
        // Check if Ctrl-Alt-Delete is pressed (assuming Ctrl, Alt, and Delete are special keys)
        if (pressed_key.ctrl() && pressed_key.alt() && pressed_key.scancode() == 0x53)
        {
            reboot();
        }
    }
}