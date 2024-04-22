/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The CGA_Stream class allows to print different data types as text strings */
/* to a PC's CGA screen.                                                     */
/* For attributes/colors and cursor positioning use the methods of class     */
/* CGA_Screen.                                                               */
/*****************************************************************************/

#include "cgastr.h"


void CGA_Stream::flush() {
    buffer[lastIndex] = '\0'; // Null-terminate the buffer
    
    // Print the buffer to the CGA screen
    int row = cursorRow;
    int col = cursorCol;
    for (char* p = buffer; *p != '\0'; p++) {
        if (*p == '\n') {
            row++;
            col = 0;
        } else {
            show(row, col++, *p, 0x07); // 0x07 is the default color attribute
            if (col >= BUFFER_SIZE) {
                row++;
                col = 0;
            }
        }
    }
    cursorRow = row;
    cursorCol = col;
    
    clearBuffer(); // Clear the buffer after printing
}

void CGA_Stream::clearBuffer() {
    Stringbuffer::clearBuffer();
    // Additional CGA-specific buffer clearing logic, if needed
}