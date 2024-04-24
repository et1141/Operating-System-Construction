/* Add your code here */
#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "object/o_stream.h"
#include "device/cgastr.h"

void test_CGA_SCREEN()
{
}

int main()
{
	/**/
	CGA_Stream cga;
	
	int x,y;

	//1. CGA_Screen test:
	cga.setpos(0,0);
	for(int i=0;i<80*24;i++){
		cga.print("1",1,4);
	}

	cga.print("\n",1,4);
	for(int i=0;i<77;i++){
		cga.print("4",1,7);
	}
	cga.print("bsfff",5,8);
	cga.print("\n",1,4);
	cga.print("bsfff",5,8);
	cga.setpos(0,23);
	cga.print("\n",1,11);

	//2,3: cga.flush();
	
	cga << "Test          <stream result> -> <expected>" << endl;
	cga << "zero:         " << 0 << " -> 0" << endl;
	cga << "decimal:      " << dec << 42 << " -> 42" << endl;
	cga << "binary:       " << bin << 42 << dec << " -> 0b101010" << endl;
	cga << "octal:        " << oct << 42 << dec << " -> 052" << endl;
	cga << "hex:          " << hex << 42 << dec << " -> 0x2a" << endl;
	cga << "uint64_t max: " << ~((unsigned long)0) << " -> 18446744073709551615" << endl;
	cga << "int64_t max:  " << ~(1l << 63) << " -> 9223372036854775807" << endl;
	cga << "int64_t min:  " << (1l << 63) << " -> -9223372036854775808" << endl;
	cga << "some int64_t: " << (-1234567890123456789) << " -> -1234567890123456789" << endl;
	cga << "some int64_t: " << (1234567890123456789) << " -> 1234567890123456789" << endl;
	cga << "pointer:      " << reinterpret_cast<void *>(1994473406541717165ul) << " -> 0x1badcafefee1dead" << endl;
	cga << "smiley:       " << static_cast<char>(1) << endl;

	// 4: keyboard test
	// For the test of the keyboard input, you should create a KeyboardController object. Use it to poll characters from the keyboard in a loop and print them with kout.
	Keyboard_Controller keyboard;
	//	keyboard.set_led(1,1);
	Key key;

	keyboard.set_repeat_rate(0, 3);
	keyboard.set_led(1, true);
	keyboard.set_led(2, true);
	keyboard.set_led(4, true);

	// Print instructions
	cga.print("\nYou are in while true loop for keyboard testing. Click q to quit", 66, 4);
	cga.print("\nClick m to set minimum(31) repeat_rate", 35,4);
	cga.print("\nClick m to set max(0) repeat_rate", 36,4);
	cga.print("\nClick c to turn on all controls", 33,4);

	// Main loop to wait for key presses
	while (true)
	{
		key = keyboard.key_hit();

		if (key.valid())
		{
			if (key.ascii() == 'q'){
				break;
			}

			if (key.ascii()=='m'){
				keyboard.set_repeat_rate(31, 3);
			}
			if (key.ascii()=='M'){
				keyboard.set_repeat_rate(0, 3);
			}
			if (key.ascii()=='c'){
				keyboard.set_led(1, true);
				keyboard.set_led(2, true);
				keyboard.set_led(4, true);
			}

			char pressedKey[2];
			pressedKey[0] = (char)key.ascii();
			pressedKey[1] = '\0'; // 1st arg of screen.print needs to be char* (not char)
			cga.print(pressedKey, 1, 6);
		}
	}

	return 0;
}