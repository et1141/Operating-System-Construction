/* Add your code here */ 
#include "machine/cgascr.h"

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
	screen.print("\n",1,11);




/* Add your code here */ 
 
/* Add your code here */ 
 
/* Add your code here */ 
 
	return 0;
}
