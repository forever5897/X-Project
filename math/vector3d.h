#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d
{
public:
    Vector3d();
    Vector3d(double x, double y, double z);
    Vector3d(double v[]);


public:
    double x, y, z;

public:
    Vector3d set(Vector3d src);

};

#endif // VECTOR3D_H
