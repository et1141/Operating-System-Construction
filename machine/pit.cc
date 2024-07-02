/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/
#include "pit.h"
#include "machine/io_port.h"

// Constants for PIT control
#define PIT_FREQUENCY 1193182 // PIT frequency in Hz
#define PIT_COMMAND 0x36      // Command byte for PIT: channel 0, lobyte/hibyte, mode 3 (square wave)
#define PIT_PORT_CHANNEL0 0x40
#define PIT_PORT_COMMAND 0x43

PIT::PIT(int us) {
    set_timer(us);
}

int PIT::interval() const {
    return current_interval;
}

void PIT::interval(int us) {
    set_timer(us);
}

void PIT::set_timer(int us) {
    current_interval = us;

    // Calculate the divisor for the desired interval
    int divisor = (PIT_FREQUENCY * us) / 1000000;

    // Send the command byte to the PIT control port
    outb(PIT_PORT_COMMAND, PIT_COMMAND);

    // Send the divisor (low byte)
    outb(PIT_PORT_CHANNEL0, divisor & 0xFF);

    // Send the divisor (high byte)
    outb(PIT_PORT_CHANNEL0, (divisor >> 8) & 0xFF);
}