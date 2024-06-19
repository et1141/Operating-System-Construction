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



/**
 * "Plugs in" the keyboard (driver). After calling keyboard interrupts are handled with the Keyboard::trigger method. 
*/
void Keyboard::plugin(){
    plugbox.assign(plugbox.keyboard, *this); //keyboard object must register at the object plugbox  
    pic.allow(pic.keyboard); // tell the PIC object pic that interrupts of the keyboard should from now on be reported to the processor
}

bool Keyboard::prologue(){
    key = key_hit();
    if (key.valid()){
        if (key.alt() && key.ctrl_left() && key.scancode() ==83 ){ //ctral+alt+del => reboot
		    reboot();
	    }
        return true;
    }
    return false;
}

void Keyboard::epilogue(){
    char pressedKey[2];
    pressedKey[0] = (char)key.ascii();
    pressedKey[1] = '\0'; // Not necessary, but for safety
    kout.setpos(0,24);
    kout.print(pressedKey, 1, 6);
}


//function from task2 - hard synchronization version
void Keyboard::trigger(){
    kout.setpos(0,24);
    Key key = key_hit();
    while (key.valid()){
        char pressedKey[2];
        pressedKey[0] = (char)key.ascii();
        pressedKey[1] = '\0'; //not necessary, but for safety        
        kout.print(pressedKey, 1, 6);
        key = key_hit();
    }
}