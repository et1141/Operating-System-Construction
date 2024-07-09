/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ O R G A N I Z E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Organizer implements the system call interface to the         */
/* Organizer.                                                                */
/*****************************************************************************/

#ifndef __Guarded_Organizer_include__
#define __Guarded_Organizer_include__

#include "syscall/thread.h"
#include "thread/organizer.h"

class Guarded_Organizer : public Organizer {
private:
	Guarded_Organizer(const Guarded_Organizer &copy); // prevent copying
public:
	Guarded_Organizer() {}
	// This method registers the process that with the scheduler.
	void ready (Thread& that);
	// This method allows a process to terminate itself.
	void exit ();
	// This method allows one process to terminate another (that).
	void kill (Thread& that);
	// This method can be used to trigger a process switch.
	void resume ();
};

#endif
