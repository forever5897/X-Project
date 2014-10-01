#include "axisangle4d.h"

AxisAngle4d::AxisAngle4d()
{
    axis = Vector3d(1, 0, 0);
}

AxisAngle4d::AxisAngle4d(Vector3d axis, double radian)
{
    this->axis = axis;
    this->radian = radian;
}

AxisAngle4d::AxisAngle4d(AxisAngle4d &src)
{
    axis = Vector3d(src.axis);
    radian = src.radian;
}


