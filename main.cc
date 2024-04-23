/* Add your code here */ 
#include "machine/cgascr.h"
#include "machine/keyctrl.h"


int main()
{	
	CGA_Screen screen; 
	int x,y;

	//1. CGA_Screen test:
	screen.setpos(0,0);
	for(int i=0;i<80*24;i++){
		screen.print("1",1,4);
	}

	screen.print("\n",1,4);
	for(int i=0;i<77;i++){
		screen.print("4",1,7);
	}
	screen.print("bsfff",5,8);
	screen.print("\n",1,4);
	screen.print("bsfff",5,8);
	screen.setpos(0,23);
	screen.print("\n",1,11);




/* Add your code here */ 
 
/* Add your code here */ 
 
/* Add your code here */ 
	

	//4: keyboard test 
	//For the test of the keyboard input, you should create a KeyboardController object. Use it to poll characters from the keyboard in a loop and print them with kout.
	Keyboard_Controller keyboard; 
//	keyboard.set_led(1,1);
	Key key;


    // Print instructions
    screen.print("\nYou are in while true loop for keyboard testing. Click q to quit", 66, 4);

    // Main loop to wait for key presses
    while (true) {
        // Poll for a key press
        key = keyboard.key_hit();

        // Check if a valid key press event occurred
        if (key.valid()) {
            // Check if the pressed key is 'q' to quit
            if (key.ascii() == 'q') {
                break; // Exit the loop if 'q' is pressed
            }
			
 	    char pressedKey[2]; 
        pressedKey[0] = (char)key.ascii(); 
        pressedKey[1] = '\0'; //screen.print need pressedKey to be char* (not char) 
        screen.print(pressedKey, 1, 6); // Drukuj znak
        }
    }

	return 0;
}
