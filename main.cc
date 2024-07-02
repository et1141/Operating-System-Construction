#include "user/appl.h"
#include "thread/dispatch.h"
#include "thread/scheduler.h"
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

    void* tos1 = stack1 + STACK_SIZE;
    void* tos2 = stack2 + STACK_SIZE;

	// Create the application coroutines
    Application app1(tos1,"1");
    Application app2(tos2,"2");

    Watch watch(1000);  

    // Wind up the Watch to start the timer and register the interrupt handler
    watch.windup();  

    scheduler.ready(app1);
    scheduler.ready(app2);

    // Start the scheduler
    scheduler.schedule();



    
    
	return 0;
}

