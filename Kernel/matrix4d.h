/**
 *             mat[0]  mat[4]  mat[8]  mat[12]
 *             mat[1]  mat[5]  mat[9]  mat[13]
 * matrix4d =  mat[2]  mat[6]  mat[10] mat[14]
 *             mat[3]  mat[7]  mat[11] mat[15]
 *
 */

#ifndef MATRIX4D_H
#define MATRIX4D_H
#include "vector3d.h"
#include "axisangle4d.h"

class Matrix4d
{
public:
    Matrix4d();
    Matrix4d(bool isZero);
    Matrix4d(double scale);
    Matrix4d(double mat[]);
    Matrix4d(double mat00, double mat01, double mat02, double mat03,
             double mat10, double mat11, double mat12, double mat13,
             double mat20, double mat21, double mat22, double mat23,
             double mat30, double mat31, double mat32, double mat33);
    Matrix4d(Matrix4d& mat);        //Uncheck
    Matrix4d(Vector3d translate);
    Matrix4d(Vector3d axis, double rad);
    Matrix4d(AxisAngle4d aa);
    Matrix4d set(double mat00, double mat01, double mat02, double mat03,
                 double mat10, double mat11, double mat12, double mat13,
                 double mat20, double mat21, double mat22, double mat23,
                 double mat30, double mat31, double mat32, double mat33);
    Matrix4d set(Matrix4d src);
    void set(int i, int j, double v);
    double at(int i, int j);

    Matrix4d setIdentity();
    double getDot(Matrix4d mat);
    Matrix4d transpose();
    Matrix4d getTranspose();
    Matrix4d add(Matrix4d src);
    Matrix4d getAdd(Matrix4d &src);
    Matrix4d substract(Matrix4d src);
    Matrix4d getSubstract(Matrix4d &src);
    Matrix4d multiR(Matrix4d src);
    Matrix4d getMultiR(Matrix4d &src);
    Matrix4d multiL(Matrix4d src);
    Matrix4d getMultiL(Matrix4d &src);
    Matrix4d multi(double s);
    Matrix4d getMulti(double s);
    double determinant();
    Matrix4d inverse();
    Matrix4d getInverse();
    Matrix4d resetScale(double s);
    float getFloatArray();
    Matrix4d scale(double s);
    Matrix4d getScale(double s);
    Matrix4d resetTranslate(Vector3d v);
    Matrix4d translate(Vector3d v);
    Matrix4d getTranslate(Vector3d v);
    Vector3d getTranslateVector3d();
//    DVector3d getDVector3d();
    Matrix4d resetRotate(AxisAngle4d aa);
    Matrix4d resetRotate(Vector3d axis, double rad);
    Matrix4d rotate(Vector3d axis, double rad);
    Matrix4d getRotate(Vector3d axis, double rad);
    Matrix4d rotate(AxisAngle4d aa);
    Matrix4d getRotate(AxisAngle4d aa);
    AxisAngle4d getAxisAngle4d();
    Matrix4d multi(Matrix4d a, Matrix4d b);

private:
    void _multiR(double a[], double b[], double c[]);

public:
    double mat[16];

};

#endif // MATRIX4D_H
