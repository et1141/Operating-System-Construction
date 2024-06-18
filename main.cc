#include "user/appl.h"
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


    // Start the first coroutine
  
 //   app1.go();
  
    app2.go();
    
	return 0;
}