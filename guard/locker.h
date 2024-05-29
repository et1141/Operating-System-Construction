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
    bool _is_free; //true if the critical section is free 

public:
    /**
     * Constructor that initializes the lock variable as free.
     */
    Locker() : _is_free(true) {}

    /**
     * Method to enter the critical section.
     * If already in the critical section, prints an error and halts the system.
     */
    void enter();

    /**
     * Method to leave the critical section.
     * If not in the critical section, prints an error and halts the system.
     */
    void retne();

    /**
     * Method to check if the critical section is free.
     * @return True if the critical section is free, false otherwise.
     */
    bool avail() const;
};

#endif
