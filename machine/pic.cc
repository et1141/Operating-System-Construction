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

/*Information about PIC: https://os.inf.tu-dresden.de/Studium/OSC/SS2024/tasks/task2/pic_info.php

*/

#include "machine/pic.h"

PIC::PIC() : pic1_port(0x21), pic2_port(0xa1){} //port to IMR (Interrupt Mask Register) 


/**
 * Configure the PIC so that it forwards interrupts for the device with the number interrupt_device to the CPU.
 * @param interrupt_device The number of the device for which the interrupts should be forwarded to the CPU.
*/
void PIC::allow(int interrupt_device) {
    if (interrupt_device > 7) {
        interrupt_device -= 7;
        int mask = pic2_port.inb() & ~(1<<interrupt_device); //0 == allow
        pic2_port.outb(mask);
    }
    else{
        int mask = pic1_port.inb() & ~(1<<interrupt_device); 
        pic1_port.outb(mask);    
        }
}


/**
* Configure the PIC so that it suppresses a specific hardware interrupt of the device number interrupt_device.
* @param interrupt_device The number of the device for which the interrupts should be suppressed.
*/
void PIC::forbid(int interrupt_device) {
    if (interrupt_device > 7) {
        interrupt_device -= 7;
        int mask = pic2_port.inb() | (1<<interrupt_device); //1 == forbid
        pic2_port.outb(mask);
    }
    else{
        int mask = pic1_port.inb() | (1<<interrupt_device); //1 == forbid
        pic1_port.outb(mask);    }

}

/**
* Determine the current state of the masking bit of a specific hardware interrupt with interrupt number interrupt_device. If interrupts of this device are not forwarded to the CPU, return true, otherwise return false.
* @param interrupt_device The number of the device for which the masking bit should be checked.
*/
bool PIC::is_masked(int interrupt_device) {
    if (interrupt_device > 7) {
        return (pic1_port.inb() >> (interrupt_device - 7)) & 0x1;
    }
    return (pic1_port.inb() >> interrupt_device) & 0x1;
}
