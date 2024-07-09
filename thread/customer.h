/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Customer class extends the Entrant class with the ability to record   */
/* and retrieve an event that the process in question is waiting for.        */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__


#include "thread/entrant.h"
#include "meeting/waitingroom.h"
#include "device/cgastr.h"

extern CGA_Stream kout;

/**
 * @brief The Customer class represents a process that can wait for events in a waiting room.
 */
class Customer : public Entrant {
private:
    Customer(const Customer &copy); // Prevent copying

    Waitingroom* waitingroom;

public:
    /**
     * @brief Constructor that forwards the tos parameter to the base class Entrant constructor.
     * @param tos Top of stack pointer.
     */
    Customer(void* tos) : Entrant(tos), waitingroom(0) {}

    /**
     * @brief Marks that the customer is currently waiting in the specified waiting room.
     * @param w Pointer to the Waitingroom object.
     */
    void waiting_in(Waitingroom* w) {
    if ((w != 0) && (waitingroom != 0)) {
        kout << endl << "waitingroom is not NULL!" << endl;
        kout.flush();
        return;
    }
    waitingroom = w;
}

    /**
     * @brief Returns the Waitingroom object in which the customer is currently registered.
     * @return Pointer to the Waitingroom object. Returns 0 if the customer is not waiting for any event.
     */
    Waitingroom* waiting_in() {
    return waitingroom;
}
};

#endif // __customer_include__


