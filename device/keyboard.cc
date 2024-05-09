/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/
#include "device/keyboard.h"
#include "user/globals.h"
#include "machine/key.h"



Keyboard::Keyboard(){
    Keyboard_Controller keyboard_controller;
}

/**
 * "Plugs in" the keyboard (driver). After calling keyboard interrupts are handled with the Keyboard::trigger method. 
*/
void Keyboard::plugin(){
    plugbox.assign(plugbox.keyboard, *this); //keyboard object must register at the object plugbox  
    pic.allow(pic.keyboard); // tell the PIC object pic that interrupts of the keyboard should from now on be reported to the processor
}


/**
 * This method responds to interrupts from the keyboard. It reads the key from the keyboard controller and prints it to the screen. When the user inputs Ctrl-Alt-Delete, the system should reboot.
*/
void Keyboard::trigger(){

    Key key = keyboard_controller.key_hit();
    if (key.valid()){
        char pressedKey[2];
        pressedKey[0] = (char)key.ascii();
        pressedKey[1] = '\0'; //not necessary, but for safety
       // kout.setpos(0,24);
        kout.print(pressedKey, 1, 6);
    }
}


 
