/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                       S T R I N G B U F F E R                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Stringbuffer class provides a buffer for collecting characters to be  */
/* printed to an output device, in our case the PC screen. The actual output */
/* occurs once the buffer is full, or when the user explicitly calls         */
/* flush().                                                                  */
/* As Stringbuffer is intended to be device independent, flush() is a        */
/* (pure) virtual method that must be defined by derived classes.            */
/*****************************************************************************/

#include "object/strbuf.h"

/* Add your code here */ 

Stringbuffer::Stringbuffer() : lastIndex(-1), numChars(0)
{
    clearBuffer();
}

Stringbuffer::~Stringbuffer()
{
    // TODO: flush() and clear() ?
}

void Stringbuffer::put (char c)
{
    if(numChars < BUFFER_SIZE)
    {
        buffer[lastIndex++]=c;
        numChars++;
    }
    else // buffer overflow
    {
        flush();
        clearBuffer();
        buffer[lastIndex++]=c;
        numChars++;
    }
}

void Stringbuffer::clearBuffer() {
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        buffer[i] = '\0'; 
    }
    numChars = 0; 
    lastIndex = -1; 
}