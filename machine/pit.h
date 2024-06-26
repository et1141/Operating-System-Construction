/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

class PIT {
public:
	PIT(const PIT &copy) = delete; // prevent copying
/* Add your code here */ 
public:
	PIT(int us) {
		interval (us);
	}
	int interval() {
/* Add your code here */ 
	}
	void interval(int us);
};

#endif
