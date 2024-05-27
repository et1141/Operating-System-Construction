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

bool Keyboard::prologue() {
    Key key = keyboard_controller.key_hit();
    if (key.valid()) {
        if (key.ctrl() && key.alt() && key.scancode() == Key::scan::del) {
            // Ctrl-Alt-Delete combination
            keyboard_controller.reboot();
        }
        return true; // Request epilogue execution
    }
    return false; // No need for epilogue
}

void Keyboard::epilogue() {
    Key key = keyboard_controller.key_hit();
    if (key.valid()) {
        char pressedKey[2];
        pressedKey[0] = (char)key.ascii();
        pressedKey[1] = '\0'; // Not necessary, but for safety
        kout.print(pressedKey, 1, 6);
    }
}

void Keyboard::trigger() {
    if (prologue()) {
        // If prologue requests epilogue execution, enqueue the epilogue
        if (!queued()) {
            queued(true);
            // Code to enqueue the epilogue
        }
    }
}

 
