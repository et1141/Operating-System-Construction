#ifndef GLOBALS_H
#define GLOBALS


#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "machine/cpu.h"
#include "machine/pic.h"    
#include "device/cgastr.h"


extern CGA_Stream kout;


extern CPU cpu;
extern Plugbox plugbox;
extern PIC pic;
extern Keyboard keyboard;


#endif // GLOBALS_H

