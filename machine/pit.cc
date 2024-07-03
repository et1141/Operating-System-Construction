/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/
#include "machine/pit.h"
#include "machine/io_port.h"
#include <stdint.h>


// Constants for PIT control
#define PIT_FREQUENCY 1193182 // PIT frequency in Hz
#define PIT_COMMAND 0x36      // Command byte for PIT: channel 0, lobyte/hibyte, mode 3 (square wave)
#define PIT_PORT_CHANNEL0 0x40
#define PIT_PORT_COMMAND 0x43


constexpr int PERIODIC_INTERRUPT = 0b010;

void PIT::interval(int us) {
    current_interval = us;

    constexpr int count_bcd = false;
    constexpr int mode = PERIODIC_INTERRUPT << 1;
    constexpr int read_write = 0b11 << 4;
    constexpr int counter = 0b00 << 6;
    constexpr int config = counter | read_write | mode | count_bcd;

    static_assert(config == 0b00110100);
    m_ctrl.outb(config);

    constexpr auto step =  (int) ((1.F / 1193182.F) * (1000.F * 1000.F) * 1000.F);
    static_assert(step == 838);
    int interval = (us * 1000 + step / 2) / step;
    if (interval > UINT16_MAX) {
        interval = UINT16_MAX;
    }
    m_t0.outb(interval & 0xFF);         // low byte
    m_t0.outb((interval & 0xFF00) >> 8);
}