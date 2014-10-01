#include "matrix4d.h"

Matrix4d::Matrix4d()
{
    mat[0] = 1;
    mat[5] = 1;
    mat[10] = 1;
    mat[15] = 1;
}

Matrix4d::Matrix4d(bool isZero)
{
    if(isZero)
        return;
    mat[0] = 1;
    mat[5] = 1;
    mat[10] = 1;
    mat[15] = 1;
}

Matrix4d::Matrix4d(double mat[])
{
    for(int i=0; i<16; i++)
        this->mat[i] = mat[i];
}

Matrix4d::Matrix4d(double mat00, double mat01, double mat02, double mat03,
                   double mat10, double mat11, double mat12, double mat13,
                   double mat20, double mat21, double mat22, double mat23,
                   double mat30, double mat31, double mat32, double mat33)
{
    set(mat00, mat01, mat02, mat03,
        mat10, mat11, mat12, mat13,
        mat20, mat21, mat22, mat23,
        mat30, mat31, mat32, mat33);
}

Matrix4d::Matrix4d(Matrix4d &mat)
{
    for(int i=0; i<16; i++)
        this->mat[i] = mat.mat[i];
}

Matrix4d::Matrix4d(Vector3d translate)
{
    resetTranslate(translate);
}

Matrix4d::Matrix4d(Vector3d axis, double rad)
{
    resetRotate(axis, rad);
}

Matrix4d::Matrix4d(AxisAngle4d aa)
{
    resetRotate(aa);
}

void Matrix4d::set(double mat00, double mat01, double mat02, double mat03,
                   double mat10, double mat11, double mat12, double mat13,
                   double mat20, double mat21, double mat22, double mat23,
                   double mat30, double mat31, double mat32, double mat33)
{
    mat[0] = mat00;
    mat[1] = mat10;
    mat[2] = mat20;
    mat[3] = mat30;
    mat[4] = mat01;
    mat[5] = mat11;
    mat[6] = mat21;
    mat[7] = mat31;
    mat[8] = mat02;
    mat[9] = mat12;
    mat[10] = mat22;
    mat[11] = mat32;
    mat[12] = mat03;
    mat[13] = mat13;
    mat[14] = mat23;
    mat[15] = mat33;
}

void Matrix4d::setIdentity()
{
    mat[0] = 1;
    mat[1] = 0;
    mat[2] = 0;
    mat[3] = 0;

    mat[4] = 0;
    mat[5] = 1;
    mat[6] = 0;
    mat[7] = 0;

    mat[8] = 0;
    mat[9] = 0;
    mat[10] = 1;
    mat[11] = 0;

    mat[12] = 0;
    mat[13] = 0;
    mat[14] = 0;
    mat[15] = 1;
}

void Matrix4d::resetRotate(Vector3d axis, double rad)
{
    double c=cos(rad);
    double _c=(1-c);
    double s=sin(rad);

    mat[0] = _c * (axis.x * axis.x) + c;
    mat[1] = _c * axis.x * axis.y + s * axis.z;
    mat[2] = _c * axis.x * axis.z - s * axis.y;
    mat[3] = 0;
    mat[4] = _c * axis.x * axis.y - s * axis.z;
    mat[5] = _c * (axis.y * axis.y) + c;
    mat[6] = _c * axis.y * axis.z + s * axis.x;
    mat[7] = 0;
    mat[8] = _c * axis.x * axis.z + s * axis.y;
    mat[9] = _c * axis.y * axis.z - s * axis.x;
    mat[10] = _c * (axis.z * axis.z) + c;
    mat[11] = 0;
    mat[12] = 0;
    mat[13] = 0;
    mat[14] = 0;
    mat[15] = 1;
}

void Matrix4d::resetRotate(AxisAngle4d aa)
{
    resetRotate(aa.axis, aa.radian);
}

void Matrix4d::resetTranslate(Vector3d v)
{
    setIdentity();
    mat[12] = v.x;
    mat[13] = v.y;
    mat[14] = v.z;
}

