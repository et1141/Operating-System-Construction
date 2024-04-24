#ifndef CGASTR_H
#define CGASTR_H

#include "object/o_stream.h"
#include "machine/cgascr.h"

class CGA_Stream : public O_Stream, public CGA_Screen {
public:

    void flush() override;
};

#endif // CGASTR_H