#ifndef GLOBALS_H
#define GLOBALS


#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "machine/cpu.h"
#include "machine/pic.h"    
#include "device/cgastr.h"
#include "machine/keyctrl.h"


extern CGA_Stream kout;
extern Keyboard_Controller keyboard_controller; //TODO delete


extern CPU cpu;
extern Plugbox plugbox;
extern PIC pic;
extern Keyboard keyboard;


#endif // GLOBALS_H

