//
// Created by mashenjun on 7-3-17.
//

#include "geometry.h"

float geometry::lengthof(tuple<float,float,float> &vector) {
    return 0;
}

bool geometry::is_orthogonal(tuple<float, float, float> &vector_x,tuple<float, float, float> &vector_y,tuple<float, float, float> &vector_z) {
    bool result = true;
    return result;
}

geometry::geometry(const tuple<float, float, float> &vector_x, const tuple<float, float, float> &vector_y,
                   const tuple<float, float, float> &vector_z) : vector_x(vector_x), vector_y(vector_y),
                                                                 vector_z(vector_z) {}

const tuple<float, float, float> &geometry::getVector_x() const {
    return vector_x;
}

void geometry::setVector_x(const tuple<float, float, float> &vector_x) {
    geometry::vector_x = vector_x;
}

const tuple<float, float, float> &geometry::getVector_y() const {
    return vector_y;
}

void geometry::setVector_y(const tuple<float, float, float> &vector_y) {
    geometry::vector_y = vector_y;
}

const tuple<float, float, float> &geometry::getVector_z() const {
    return vector_z;
}

void geometry::setVector_z(const tuple<float, float, float> &vector_z) {
    geometry::vector_z = vector_z;
}
