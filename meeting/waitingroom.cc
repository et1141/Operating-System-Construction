/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements a list of processes (Customer objects) that are all waiting    */
/* for a specific event.                                                     */
/*****************************************************************************/

#include "waitingroom.h"

Waitingroom::~Waitingroom() {
    // Wake up all customers before destruction
    for (auto customer : customers) {
        // Assume Customer class has a method to wake up the process.
        customer->wakeUp();
    }
    customers.clear();
}

void Waitingroom::remove(Customer* customer) {
    customers.remove(customer);
    // Assume Customer class has a method to wake up the process.
    customer->wakeUp();
}
