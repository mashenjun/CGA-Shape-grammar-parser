

#ifndef CGA_SHAPE_SHAPE_H
#define CGA_SHAPE_SHAPE_H

using namespace std;

#include <string>
#include "geometry.h"

class shape {
    private:
        string _id;
        string name;
        bool _terminal;
        geometry position;

public:
    shape(const string &_id, const string &name, bool _terminal, const geometry &position);

};


#endif //CGA_SHAPE_SHAPE_H
