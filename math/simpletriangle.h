#ifndef SIMPLETRIANGLE_H
#define SIMPLETRIANGLE_H
#include "vector3d.h"


class SimpleTriangle
{
public:
    SimpleTriangle();
public:
    Vector3d vertex[3];
    Vector3d normal;
};

#endif // SIMPLETRIANGLE_H
