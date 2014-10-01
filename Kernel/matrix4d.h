#ifndef MATRIX4D_H
#define MATRIX4D_H
#include "vector3d.h"
#include "axisangle4d.h"
#include "simpletriangle.h"
#include <vector>
#include <cmath>

class Matrix4d
{
public:
    Matrix4d();
    Matrix4d(bool isZero);
    Matrix4d(double scale);
    Matrix4d(double mat[]);
    Matrix4d(double mat00,double mat01,double mat02,double mat03
            ,double mat10,double mat11,double mat12,double mat13
            ,double mat20,double mat21,double mat22,double mat23
            ,double mat30,double mat31,double mat32,double mat33);
    Matrix4d(Matrix4d &mat);
    Matrix4d(Vector3d translate);           //generate tranlation matrix
    Matrix4d(Vector3d axis, double rad);    //generate rotation matrix, given axis and radian
    Matrix4d(AxisAngle4d aa);

public:
    void set(double mat00,double mat01,double mat02,double mat03
            ,double mat10,double mat11,double mat12,double mat13
            ,double mat20,double mat21,double mat22,double mat23
            ,double mat30,double mat31,double mat32,double mat33);
    void setIdentity();
    void resetRotate(Vector3d axis, double rad);
    void resetRotate(AxisAngle4d aa);
    void resetTranslate(Vector3d v);
//    vector<SimpleTriangle>

public:
    double mat[16];
};

#endif // MATRIX4D_H
