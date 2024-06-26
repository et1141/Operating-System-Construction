#ifndef GLOBALS_H
#define GLOBALS


#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "machine/cpu.h"
#include "machine/pic.h"    
#include "device/cgastr.h"
#include "guard/guard.h"
#include "thread/scheduler.h"


extern CGA_Stream kout;


extern Guard guard;
extern CPU cpu;
extern Plugbox plugbox;
extern PIC pic;
extern Keyboard keyboard;
extern Scheduler scheduler;

#endif // GLOBALS_H

