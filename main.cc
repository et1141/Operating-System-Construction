/* Add your code here */ 
#include "machine/cgascr.h"
#include "object/o_stream.h"
int main()
{	
	O_Stream kout;
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
	screen.print("\n",1,11);

	kout << "Test          <stream result> -> <expected>" << endl;
	kout << "zero:         " << 0 << " -> 0" << endl;
	kout << "decimal:      " << dec << 42 << " -> 42" << endl;
	kout << "binary:       " << bin << 42 << dec << " -> 0b101010" << endl;
	kout << "octal:        " << oct << 42 << dec << " -> 052" << endl;
	kout << "hex:          " << hex << 42 << dec << " -> 0x2a" << endl;
	kout << "uint64_t max: " << ~((unsigned long)0) << " -> 18446744073709551615" << endl;
	kout << "int64_t max:  " << ~(1l<<63) << " -> 9223372036854775807" << endl;
	kout << "int64_t min:  " << (1l<<63) << " -> -9223372036854775808" << endl;
	kout << "some int64_t: " << (-1234567890123456789) << " -> -1234567890123456789" << endl;
	kout << "some int64_t: " << (1234567890123456789) << " -> 1234567890123456789" << endl;
	kout << "pointer:      " << reinterpret_cast<void*>(1994473406541717165ul) << " -> 0x1badcafefee1dead" << endl;
	kout << "smiley:       " << static_cast<char>(1) << endl;


/* Add your code here */ 
 
/* Add your code here */ 
 
/* Add your code here */ 
 
	return 0;
}
