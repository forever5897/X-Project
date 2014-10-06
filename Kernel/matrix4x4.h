#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include <vector>
#include "vector3d.h"

class Matrix4x4
{
public:
    Matrix4x4(void) {setIdentity();}
    Matrix4x4(double f) {constant(f);}
    Matrix4x4(const double *m);
    Matrix4x4(const Matrix4x4& m) {loadMatrix(m);}
    ~Matrix4x4(void){}
    double mat[16];

    void multPoint3d(const Vector3d oldPt, Vector3d newPt) const;
//    void multPointArray_3d(int numPts, vector<Vector3d> *oldPts, vector<Vector3d> *newPts) const;
    void multNorm3d(const Vector3d oldNorm, Vector3d newNorm) const;
    void multPlaneEq3d(const Vector3d, Vector3d) const;
//    void multPoint4d(const Vector3d)


    void setIdentity();
    void constant(double f);
    void loadMatrix(const Matrix4x4 &m);
    Matrix4x4& operator = (const Matrix4x4& m) {loadMatrix(m); return *this;}

    void multMatrix(const Matrix4x4&);
    int inverse(void);
    void transpose();
    void rot(double, char);  //angle is degree
    void rotateAxis(const Vector3d, double angle);
    void transvec(double x, double y, double z);
    void transvecInv(double x, double y, double z);
    void translate(double, double, double);
    void translate(Vector3d d) {translate(d.x, d.y, d.z);}

    void scale(double, double, double);
    void scale(double f) {scale(f, f, f);}

};

#endif // MATRIX4X4_H
