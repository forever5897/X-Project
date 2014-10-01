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
    m[0] = 1;
    m[5] = 1;
    m[10] = 1;
    m[15] = 1;
}

Matrix4d::Matrix4d(double scale)
{
    m[0] = scale;
    m[5] = scale;
    m[10] = scale;
    m[15] = 1;
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

Matrix4d::set(double mat00, double mat01, double mat02, double mat03,
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

Matrix4d::set(Matrix4d src)
{
    for(int i=0; i<16; i++)
        this->mat[i] = src.mat[i];
    return this;
}

double Matrix4d::at(int i, int j)
{
    return m[i + j * 4];
}

void Matrix4d::set(int i, int j, double v)
{
    m[i + j * 4] = v;
}

Matrix4d::setIdentity()
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

//Uncheck
double Matrix4d::getDot(Matrix4d mat)
{
    double sum = 0;
    for(int i=0; i<16; i++)
        sum += this->mat[i] * mat.mat[i];
    return sum;
}

Matrix4d::transpose()
{
    double t;
    t = m[1];
    m[1] = m[4];
    m[4] = t;

    t = m[2];
    m[2] = m[8];
    m[8] = t;

    t = m[3];
    m[3] = m[12];
    m[12] = t;

    t = m[6];
    m[6] = m[5];
    m[5] = t;

    t = m[7];
    m[7] = m[13];
    m[13] = t;

    t = m[11];
    m[11] = m[14];
    m[14] = t;

    return this;
}







