#include <math.h>
#include <iostream>
#include "matrix4x4.h"

//Construct, for the case when an array of floating-point numbers is given
Matrix4x4::Matrix4x4(const double *m)
{
    memcpy((void *)mat, (const void *)m, 16 * sizeof(double));
}

// multiplies a 3D point(first arg) by the Matrix, returns in 2nd arg
void Matrix4x4::multPoint3d(const Vector3d oldPt, Vector3d newPt) const
{
 #if 0
    //should try re-testing this formulation to see if it outperforms
    //the old one, without introducing floating point imprecision
    float itemp3 = 1.0 / (oldPt.x * mat[3] + oldPt.y * mat[7] + oldPt.z * mat[11] + mat[15]);

    newPt.x = itemp3 * (oldPt.x * mat[0] + oldPt.y * mat[4] + oldPt.z * mat[8] + mat[12]);
    newPt.y = itemp3 * (oldPt.x * mat[1] + oldPt.y * mat[5] + oldPt.z * mat[9] + mat[13]);
    newPt.z = itemp3 * (oldPt.x * mat[2] + oldPt.y * mat[6] + oldPt.z * mat[10] + mat[14]);
 #else
    double temp[3];
    double itemp3 = 1.0 / (oldPt.x * mat[3] + oldPt.y * mat[7] + oldPt.z * mat[11] + mat[15]);

    temp[0] = itemp3 * oldPt.x;
    temp[1] = itemp3 * oldPt.y;
    temp[2] = itemp3 * oldPt.z;

    newPt.x = temp[0] * mat[0] + temp[1] * mat[4] + temp[2] * mat[8] + itemp3 * mat[12];
    newPt.y = temp[0] * mat[1] + temp[1] * mat[5] + temp[2] * mat[9] + itemp3 * mat[13];
    newPt.z = temp[0] * mat[2] + temp[1] * mat[6] + temp[2] * mat[10] + itemp3 * mat[14];
 #endif
}

// multiplies 3D point array(2nd arg) by the Matrix, returns in 3rd arg
//void Matrix4x4::multPointArray_3d(int numPts, vector<Vector3d> *oldPts, vector<Vector3d> *newPts) const
//{
//    for(int i=0; i<numPts; i++)
//    {
//        multPoint3d(&oldPts, &newPts);
//    }

//}

// multiplies a 3D norm(first arg) by the Matrix, returns in second arg
// This differs from point multiplication in that the translation operations
// are ignored.
void Matrix4x4::multNorm3d(const Vector3d oldNorm, Vector3d newNorm) const
{
    double temp[4];
    temp[0] = oldNorm.x * mat[0] + oldNorm.y * mat[4] + oldNorm.z * mat[8];
    temp[1] = oldNorm.x * mat[1] + oldNorm.y * mat[5] + oldNorm.z * mat[9];
    temp[2] = oldNorm.x * mat[2] + oldNorm.y * mat[6] + oldNorm.z * mat[10];
    temp[3] = oldNorm.x * mat[3] + oldNorm.y * mat[7] + oldNorm.z * mat[11];

    double itemp = 1.0 / sqrt(temp[0] * temp[0] + temp[1] * temp[1] + temp[2] * temp[2]);
    newNorm.x = temp[0] * itemp;
    newNorm.y = temp[1] * itemp;
    newNorm.z = temp[2] * itemp;
}

// multiplies a 3D texture plane equation by the Matrix
// This differs from multiplication in that the translation operations
// are ignored.
void Matrix4x4::multPlaneEq3d(const Vector3d oldNorm, Vector3d newNorm) const
{
//    double xvec[3] = {1.0, 0.0, 0.0};
//    double yvec[3] = {0.0, 1.0, 0.0};
//    double zvec[3] = {0.0, 0.0, 1.0};
//    double xvnew[3], yvnew[3], zvnew[3];

    Vector3d xvec(1.0, 0.0, 0.0);
    Vector3d yvec(0.0, 1.0, 0.0);
    Vector3d zvec(0.0, 0.0, 1.0);
    Vector3d xvnew, yvnew, zvnew;
    multNorm3d(xvec, xvnew);
    multNorm3d(yvec, yvnew);
    multNorm3d(zvec, zvnew);

    newNorm.x = oldNorm.x * xvnew.x + oldNorm.y * yvec.x + oldNorm.z * zvnew.x;
    newNorm.y = oldNorm.x * xvnew.y + oldNorm.y * yvec.y + oldNorm.z * zvnew.y;
    newNorm.z = oldNorm.x * xvnew.z + oldNorm.y * yvec.z + oldNorm.z * zvnew.z;
}

// clear the matrix(resets it to indetity)
void Matrix4x4::setIdentity()
{
    memset((void*)mat, 0, 16 * sizeof(double));
    mat[0] = 1.0;
    mat[5] = 1.0;
    mat[10] = 1.0;
    mat[15] = 1.0;
}

// sets the matrix so all items are the given constant value
void Matrix4x4::constant(double f)
{
    for(int i=0; i<16; mat[i++] = f);
}

// return the inverse of this matrix, that is,
// the inverse of the rotation, the inverse of the scaling, and
// the opposite of the translation vector.
int Matrix4x4::inverse()
{
    float matr[4][4], ident[4][4];
    int i, j, k, l, ll;   //need to do local scope check!!
    int icol = 0, irow = 0;



    return 0;
}
