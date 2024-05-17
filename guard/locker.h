/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Locker class implements a lock that can be used to protect critical   */
/* sections. However, the variable only indicates whether the critical       */
/* section is free. Potentially necessary waiting, and protection for        */
/* counting functionality, must be implemented elsewhere.                    */
/*****************************************************************************/


#ifndef __Locker_include__
#define __Locker_include__


class Locker {
private:
	bool lock;
public:
	Locker(const Locker &copy) = delete; // prevent copying
	/**
	 * Constructor that initializes the lock variable (free).
	*/
	Locker(){lock=false;}
	/**
	 * This method must be called when entering the critical section.
	*/
	void enter ();

	/**
	 * This method must be called when leaving the critical section.
	*/
	void retne ();
	
	/**
	 * Indicates whether the critical section is free. 
	*/
	bool avail (){return lock;}
};

#endif
