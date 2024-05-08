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

bool PIC::is_masked(int interrupt_device) {
    if (interrupt_device > 7) {
        return (pic1_port.inb() >> (interrupt_device - 7)) & 0x1;
    }
    return (pic1_port.inb() >> interrupt_device) & 0x1;
}
