

#ifndef CGA_SHAPE_TERMINALSHAPE_H
#define CGA_SHAPE_TERMINALSHAPE_H

#include "shape.h"

class terminalShape: public shape {
public:
    terminalShape(const string &_id, const string &name, const geometry &position);

};


#endif //CGA_SHAPE_TERMINALSHAPE_H
