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
    // Constructor that initializes the timer with the given interval in microseconds
    PIT(int us);

    // Returns the currently set interrupt interval
    int interval() const;

    // Sets a new interrupt interval in microseconds
    void interval(int us);

private:
    int current_interval;

    // Sets the PIT timer with the given interval
    void set_timer(int us);
};


#endif
