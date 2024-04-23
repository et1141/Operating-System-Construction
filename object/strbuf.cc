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

/**
 * @brief Default constructor for Stringbuffer.
 * Initializes lastIndex to -1 and numChars to 0, and clears the buffer.
 */
Stringbuffer::Stringbuffer() : lastIndex(-1), numChars(0)
{
    clearBuffer();
}

/**
 * @brief Destructor for Stringbuffer.
 * TODO: Consider adding flush() and clear() operations.
 */
Stringbuffer::~Stringbuffer()
{
    // TODO: flush() and clear() ?
}

/**
 * @brief Puts a character into the buffer.
 * If the buffer is not full, the character is added and the counters are updated.
 * If the buffer is full, it is flushed and cleared before the character is added.
 * @param c The character to be added to the buffer.
 */
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

/**
 * @brief Clears the buffer.
 * Sets all characters in the buffer to '\0', and resets numChars and lastIndex.
 */
void Stringbuffer::clearBuffer() {
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        buffer[i] = '\0'; 
    }
    numChars = 0; 
    lastIndex = -1; 
}