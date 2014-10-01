#ifndef AXISANGLE4D_H
#define AXISANGLE4D_H
#include "vector3d.h"

class AxisAngle4d
{
public:
    AxisAngle4d();
    AxisAngle4d(Vector3d axis, double radian);
    AxisAngle4d(AxisAngle4d &src);
public:
    Vector3d axis;
    double radian;

};

#endif // AXISANGLE4D_H
