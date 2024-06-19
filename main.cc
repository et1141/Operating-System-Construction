#include "user/appl.h"
#include "thread/dispatch.h"
#include "thread/scheduler.h"
#include <stdlib.h>
#include <stdlib.h>

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

    // Create the dispatcher
    Dispatcher dispatcher;
    dispatcher.go(app1);
    
    dispatcher.dispatch(app2);
      
    Scheduler scheduler;

    scheduler.ready(app1);
    scheduler.ready(app2);

    // Start the scheduler
    scheduler.schedule();

    
    
	return 0;
}

