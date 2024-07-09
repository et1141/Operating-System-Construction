/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Bell is an abstract base class that allows the time-controlled triggering */
/* of an activity. For this purpose, it has an internal counter that is      */
/* managed by the Bellringer.                                                */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include "object/chain.h"
#include "device/cgastr.h"

extern CGA_Stream cout; 
class Bell
: public Chain
{
private:
	Bell(const Bell &copy); // prevent copying
	int counter; 

public:
	Bell():counter(0) {}

	// Set or get the counter
	void wait (int value) {
		counter = value;
	}

	int wait () {
		return counter;
	}

	void tick () {
		--counter;
	}

	// Check whether the counter has run down.
	bool run_down() {
		if (counter <= 0)
			return true;
		return false;

	}

	// The bell rings
	virtual void ring () = 0;
};

#endif
