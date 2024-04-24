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

/**
 * @brief Default constructor for O_Stream.
 * Initializes number_system to 10.
 */
O_Stream::O_Stream() : number_system(10)
{
}

/**
 * @brief Overloaded operator<< for unsigned char.
 * This function casts the unsigned char to char and calls the put function.
 * @param c The unsigned char to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(unsigned char c)
{
    put(static_cast<char>(c));
    return *this;
}

/**
 * @brief Overloaded operator<< for char.
 * This function calls the put function.
 * @param c The char to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(char c)
{
    put(c);
    return *this;
}

/**
 * @brief Overloaded operator<< for unsigned short.
 * This function casts the unsigned short to unsigned long and calls the printNumber function.
 * @param number The unsigned short to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(unsigned short number)
{
    return printNumber(static_cast<unsigned long>(number));
}

/**
 * @brief Overloaded operator<< for short.
 * This function casts the short to long and calls the printNumber function.
 * @param number The short to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(short number)
{
    return printNumber(static_cast<long>(number));
}

/**
 * @brief Overloaded operator<< for unsigned int.
 * This function casts the unsigned int to unsigned long and calls the printNumber function.
 * @param number The unsigned int to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(unsigned int number)
{
    return printNumber(static_cast<unsigned long>(number));
}

/**
 * @brief Overloaded operator<< for int.
 * This function casts the int to long and calls the printNumber function.
 * @param number The int to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(int number)
{
    return printNumber(static_cast<long>(number));
}

/**
 * @brief Overloaded operator<< for unsigned long.
 * This function calls the printNumber function.
 * @param number The unsigned long to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(unsigned long number)
{
    return printNumber(number);
}

/**
 * @brief Overloaded operator<< for long.
 * This function calls the printNumber function.
 * @param number The long to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(long number)
{
    return printNumber(number);
}

/**
 * @brief Overloaded operator<< for void pointer.
 * This function converts the pointer to a hexadecimal string and calls the operator<< function.
 * @param pointer The pointer to be printed.
 * @return A reference to the O_Stream object.
 */
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

/**
 * @brief Overloaded operator<< for const char pointer.
 * This function prints the string pointed to by the pointer.
 * @param text The string to be printed.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(const char *text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        put(text[i]);
    }
    return *this;
}

/**
 * @brief Overloaded operator<< for function pointer.
 * This function calls the function pointed to by the function pointer.
 * @param fkt The function to be called.
 * @return A reference to the O_Stream object.
 */
O_Stream &O_Stream::operator<<(O_Stream &(*fkt)(O_Stream &))
{
    return fkt(*this);
}

/**
 * @brief Prints an unsigned long number.
 * This function converts the number to a string and calls the operator<< function.
 * @param number The number to be printed.
 * @return A reference to the O_Stream object.
 */
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

/**
 * @brief Prints a long number.
 * This function converts the number to a string and calls the operator<< function.
 * If the number is negative, it prints a '-' before the number.
 * @param number The number to be printed.
 * @return A reference to the O_Stream object.
 */
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

// Manipulators

/**
 * @brief Manipulator function for endl.
 * This function flushes the O_Stream object.
 * @param os The O_Stream object to be manipulated.
 * @return A reference to the O_Stream object.
 */
O_Stream &endl(O_Stream &os)
{
    os.put('\n');
    os.flush();
    return os;
}

/**
 * @brief Manipulator function for bin.
 * This function sets the number system of the O_Stream object to binary.
 * @param os The O_Stream object to be manipulated.
 * @return A reference to the O_Stream object.
 */
O_Stream &bin(O_Stream &os)
{
    os.number_system = 2;
    return os;
}

/**
 * @brief Manipulator function for oct.
 * This function sets the number system of the O_Stream object to octal.
 * @param os The O_Stream object to be manipulated.
 * @return A reference to the O_Stream object.
 */
O_Stream &oct(O_Stream &os)
{
    os.number_system = 8;
    return os;
}

/**
 * @brief Manipulator function for dec.
 * This function sets the number system of the O_Stream object to decimal.
 * @param os The O_Stream object to be manipulated.
 * @return A reference to the O_Stream object.
 */
O_Stream &dec(O_Stream &os)
{
    os.number_system = 10;
    return os;
}

/**
 * @brief Manipulator function for hex.
 * This function sets the number system of the O_Stream object to hexadecimal.
 * @param os The O_Stream object to be manipulated.
 * @return A reference to the O_Stream object.
 */
O_Stream &hex(O_Stream &os)
{
    os.number_system = 16;
    return os;
}
