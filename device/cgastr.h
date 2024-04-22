#ifndef CGASTR_H
#define CGASTR_H

#include "object/o_stream.h"
#include "machine/cgascr.h"

class CGA_Stream : protected O_Stream, public CGA_Screen {
public:
    void flush() override;
    void clearBuffer();

    private:
        int cursorRow = 0;
    int cursorCol = 0;
};

#endif // CGASTR_H