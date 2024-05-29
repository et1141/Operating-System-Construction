#include "user/globals.h"
#include "guard/locker.h"


void Locker::enter() {
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
    void Locker::retne() {
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
    bool Locker::avail() const {
        return _is_free;
    }