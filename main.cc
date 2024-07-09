#include "user/appl.h"
#include "thread/dispatch.h"
#include "device/watch.h"
#include <stdlib.h>
#include <stdlib.h>
#include "user/globals.h"

#define STACK_SIZE 512

// Allocate memory for the stacks
char stack1[STACK_SIZE];
char stack2[STACK_SIZE];



int main()
{
    guard.enter();
    cpu.enable_int();
    keyboard.plugin();
    Watch watch(1000);  
    watch.windup();  
    
     
    Locker locker;
    void* tos1 = stack1 + STACK_SIZE;
    void* tos2 = stack2 + STACK_SIZE;

	// Create the application coroutines
    Application app1(tos1,"1");
    Application app2(tos2,"2");



    // Wind up the Watch to start the timer and register the interrupt handler

    scheduler.Scheduler::ready(app1);
    scheduler.Scheduler::ready(app2);

    // Start the scheduler

    scheduler.Scheduler::schedule();
    
	return 0;
}

