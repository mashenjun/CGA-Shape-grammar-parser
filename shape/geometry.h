//
// Created by mashenjun on 7-3-17.
//
#include <tuple>
#ifndef CGA_SHAPE_POSITION_H
#define CGA_SHAPE_POSITION_H

using namespace std;

class geometry {
    /**
     *
     * this object stores the geometric attributes
     */
    private:
        tuple<float,float,float> vector_x;
        tuple<float,float,float> vector_y;
        tuple<float,float,float> vector_z;

    public:
        geometry(const tuple<float, float, float> &vector_x, const tuple<float, float, float> &vector_y,
            const tuple<float, float, float> &vector_z);
        float lengthof(tuple<float,float,float> &vector);
        bool is_orthogonal(tuple<float, float, float> &vector_x,tuple<float, float, float> &vector_y,tuple<float, float, float> &vector_z);

        const tuple<float, float, float> &getVector_x() const;

        void setVector_x(const tuple<float, float, float> &vector_x);

        const tuple<float, float, float> &getVector_y() const;

        void setVector_y(const tuple<float, float, float> &vector_y);

        const tuple<float, float, float> &getVector_z() const;

        void setVector_z(const tuple<float, float, float> &vector_z);

};


#endif //CGA_SHAPE_POSITION_H
