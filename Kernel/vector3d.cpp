#include "vector3d.h"

Vector3d::Vector3d()
{
    x = y = z = 0.0;
}

Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3d::Vector3d(double v[]) {
    x = v[0];
    y = v[1];
    z = v[2];
}
