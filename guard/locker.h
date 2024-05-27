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

#include "user/globals.h"

class Locker {
private:
    bool _is_free;

public:
    /**
     * Constructor that initializes the lock variable as free.
     */
    Locker() : _is_free(true) {}

    /**
     * Method to enter the critical section.
     * If already in the critical section, prints an error and halts the system.
     */
    void enter() {
        if (!_is_free) {
            // Error: Trying to enter an already occupied critical section
            kout << "Locker: Error - re-entering critical section!\n";
            cpu.halt();
        }
        _is_free = false;
    }

    /**
     * Method to leave the critical section.
     * If not in the critical section, prints an error and halts the system.
     */
    void retne() {
        if (_is_free) {
            // Error: Trying to leave a non-occupied critical section
            kout << "Locker: Error - leaving non-occupied critical section!\n";
            cpu.halt();
        }
        _is_free = true;
    }

    /**
     * Method to check if the critical section is free.
     * @return True if the critical section is free, false otherwise.
     */
    bool avail() const {
        return _is_free;
    }
};

#endif
