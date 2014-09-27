#include <iostream>
#include "readstl.h"
using namespace std;

int main()
{
    ReadStl obj;

    obj.readAscii("../ReadStl/SphereASCII.stl");

    for(int i=0; i<obj.m_triPt.size(); i++)
    {
        cout << obj.m_triPt[i].normal.x << endl;
    }


    return 0;
}

