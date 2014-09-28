#ifndef READSTL_H
#define READSTL_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "../math/simpletriangle.h"

using namespace std;

class ReadStl
{
public:
    ReadStl();

public:
    vector<SimpleTriangle> m_triPt;

public:
    void read(string fileName);
    void readAscii(string fileName);
    void readBinary(string fileName);

private :
    static bool isAscii(string fileName);
    static bool isBinary(string fileName);

};

#endif // READSTL_H
