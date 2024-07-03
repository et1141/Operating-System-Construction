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

#include "machine/io_port.h"

class PIT {
private:
    int current_interval = 0;
    IO_Port m_ctrl{0x43};
    IO_Port m_t0{0x40};

public:
    PIT(const PIT &copy) = delete;
    // Constructor that initializes the timer with the given interval in microseconds
    PIT(int us){interval(us);};

    // Returns the currently set interrupt interval
    int interval() { return current_interval;}

    // Sets a new interrupt interval in microseconds
    void interval(int us);


};


#endif
