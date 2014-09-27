#include <iostream>
#include "readstl.h"
using namespace std;

int main()
{
    ReadStl obj;

//    obj.isAscii("../ReadStl/SphereBinary.stl");
//    obj.readAscii("../ReadStl/SphereBinary.stl");

    obj.read("../ReadStl/SphereBinary.stl");
    for(int i=0; i<obj.m_triPt.size(); i++)
    {
        cout << obj.m_triPt[i].normal.x << endl;
    }


    return 0;
}

