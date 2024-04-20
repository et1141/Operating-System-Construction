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

#include "object/o_stream.h"

O_Stream &O_Stream::operator<<(unsigned char c)
{
    put(static_cast<char>(c));
    return *this;
}

O_Stream &O_Stream::operator<<(char c)
{
    put(c);
    return *this;
}

O_Stream &O_Stream::operator<<(unsigned short number)
{
    return printNumber(static_cast<unsigned long>(number));
}

O_Stream &O_Stream::operator<<(short number)
{
    return printNumber(static_cast<long>(number));
}

O_Stream &O_Stream::operator<<(unsigned int number)
{
    return printNumber(static_cast<unsigned long>(number));
}

O_Stream &O_Stream::operator<<(int number)
{
    return printNumber(static_cast<long>(number));
}

O_Stream &O_Stream::operator<<(unsigned long number)
{
    return printNumber(number);
}

O_Stream &O_Stream::operator<<(long number)
{
    return printNumber(number);
}

O_Stream &O_Stream::operator<<(void *pointer)
{
    const char *hexDigits = "0123456789abcdef";
    char buffer[17];
    char *pos = buffer + sizeof(buffer) - 1;
    *pos-- = '\0'; // Null-terminate the string

    unsigned long addr = reinterpret_cast<unsigned long>(pointer);
    do
    {
        *pos-- = hexDigits[addr & 0xf];
        addr >>= 4;
    } while (addr != 0);

    *pos = '0';
    *(pos - 1) = 'x';

    (*this) << (pos - 1);
    return *this;
}

O_Stream &O_Stream::operator<<(const char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        put(text[i]);
    }
    return *this;
}

O_Stream &O_Stream::operator<<(O_Stream &(*fkt)(O_Stream &))
{
    return fkt(*this);
}

O_Stream &O_Stream::printNumber(unsigned long number)
{
    char buffer[65];
    char *pos = buffer;
    int shift = 0;

    do
    {
        int digit = number % number_system;
        *pos++ = "0123456789abcdef"[digit];
        number /= number_system;
        shift++;
    } while (number != 0);

    *pos = '\0'; // null terminate the string
    pos--;       // move the pointer back to the last character

    // reverse the string
    for (int i = 0; i < shift / 2; i++)
    {
        char temp = pos[-i];
        pos[-i] = buffer[i];
        buffer[i] = temp;
    }

    (*this) << buffer;
    return *this;
}

O_Stream &O_Stream::printNumber(long number)
{
    if (number < 0)
    {
        put('-');
        return printNumber(static_cast<unsigned long>(-number));
    }
    else
    {
        return printNumber(static_cast<unsigned long>(number));
    }
}

