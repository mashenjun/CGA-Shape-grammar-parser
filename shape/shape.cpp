//
// Created by mashenjun on 7-3-17.
//

#include "shape.h"


shape::shape(const string &_id, const string &name, bool _terminal, const geometry &position) : _id(_id), name(name),
                                                                                                _terminal(_terminal),
                                                                                                position(position) {}
