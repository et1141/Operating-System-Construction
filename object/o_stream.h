/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"

class O_Stream : protected Stringbuffer
{
private:
	int number_system;
	O_Stream &printNumber(unsigned long number);
	O_Stream &printNumber(long number);

public:
	O_Stream(const O_Stream &copy) = delete; // prevent copying

	O_Stream &operator<<(unsigned char c);
	O_Stream &operator<<(char c);
	O_Stream &operator<<(unsigned short number);
	O_Stream &operator<<(short number);
	O_Stream &operator<<(unsigned int number);
	O_Stream &operator<<(int number);
	O_Stream &operator<<(unsigned long number);
	O_Stream &operator<<(long number);
	O_Stream &operator<<(void *pointer);
	O_Stream &operator<<(const char *text);
	O_Stream &operator<<(O_Stream &(*fkt)(O_Stream &));

	// Manipulator functions
	O_Stream &endl(O_Stream &os);
	O_Stream &bin(O_Stream &os);
	O_Stream &oct(O_Stream &os);
	O_Stream &dec(O_Stream &os);
	O_Stream &hex(O_Stream &os);
};

#endif
