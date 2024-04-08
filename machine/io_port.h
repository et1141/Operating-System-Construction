#ifndef __io_port_include__
#define __io_port_include__

/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              I O _ P O R T                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accesses to x86's I/O address space. This special       */
/* address space can only be accessed with the machine instructions 'in' and */
/* 'out'. An IO_Port object is bound to a specific I/O address (called       */
/* "port") at instantiation time and can then be used for byte- or word-wise */
/* input or output operations.                                               */
/*****************************************************************************/

/* USED FUNCTIONS */

extern "C" void outb(int port, int value);
extern "C" void outw(int port, int value);
extern "C" unsigned char inb(int port);
extern "C" unsigned short inw(int port);

/* CLASS DEFINITION */

class IO_Port {
	// copying is allowed

	// address in I/O address space ("port")
	int address;

public:
	IO_Port(int a) : address(a){};

	// OUTB: Byte-wise output via an I/O port.
	void outb(int val) const { ::outb(address, val); };

	// OUTW: Word-wise output via an I/O port.
	void outw(int val) const { ::outw(address, val); };

	// INB: Byte-wise input via an I/O port.
	int inb() const { return ::inb(address); };

	// INW: Word-wise input via an I/O port.
	int inw() const { return ::inw(address); };
};

#endif
