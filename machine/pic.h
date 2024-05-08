/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* By using the PIC, hardware interrupts can be enabled or suppressed        */
/* individually. This way we can control whether interrupts of a specific    */
/* device are forwarded to the CPU at all. Even then, the interrupt handler  */
/* gets only activated if the CPU is ready to react to interrupts. This can  */
/* be controlled by using class CPU.                                         */
/*****************************************************************************/

#ifndef __pic_include__
#define __pic_include__

#include "machine/io_port.h"


class PIC {
private:
    const IO_Port pic1_port;
    const IO_Port pic2_port;

public:
	enum {timer    = 0, keyboard = 1};

	PIC(const PIC &copy) = delete; // prevent copying
	PIC();
	/**
	 * Configure the PIC so that it forwards interrupts for the device with the number interrupt_device to the CPU.
	 * @param interrupt_device The number of the device for which the interrupts should be forwarded to the CPU.
	*/
	void allow (int interrupt_device);
	/**
	* Configure the PIC so that it suppresses a specific hardware interrupt of the device number interrupt_device.
	* @param interrupt_device The number of the device for which the interrupts should be suppressed.
	*/
	void forbid (int interrupt_device);
	/**
 	* Determine the current state of the masking bit of a specific hardware interrupt with interrupt number interrupt_device. If interrupts of this device are not forwarded to the CPU, return true, otherwise return false.
 	* @param interrupt_device The number of the device for which the masking bit should be checked.
	*/
	bool is_masked (int interrupt_device);
	};

#endif
