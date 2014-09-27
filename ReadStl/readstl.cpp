#include "readstl.h"
#include <fstream>
using namespace std;

ReadStl::ReadStl()
{
}

void ReadStl::read(string fileName) {
    if(isAscii(fileName) == true)
        readAscii(fileName);
    else
        readBinary(fileName);
}

bool ReadStl::isAscii(string fileName)
{
    string temp_str;
    ifstream file(fileName, ios::in);
    if(!file.is_open())
        return 0;
    else
    {
        file >> temp_str;
        if(temp_str == "solid")
            return 0;
        else
            return 1;
    }

    //test
    ReadStl *temp;
    temp->readAscii(fileName);
}

bool ReadStl::isBinary(string fileName)
{
    int num = 0;
    std::streamoff size = 0, begin = 0, end = 0;
    ifstream file(fileName, ios::binary | ios::in);

    if(!file.is_open())
        return 0;
    else
    {
        begin = file.tellg();
        file.seekg(80);
        file.read((char *)(&num), sizeof(int));
        if(num < 0)
            return 0;
        file.seekg(0, ios::end);
        end = file.tellg();
        file.close();
        size = end - begin;

        if((84 + num * 50) != size)
            return 0;
        else
            return 1;
    }
}

void ReadStl::readAscii(string fileName) {
    int cnt = 0, cnt1 = 0, cnt2 = 0, fileName_index = 0;
    SimpleTriangle* temp_tri = new SimpleTriangle();
    ifstream file(fileName, ios::in);

    //Set label[1]'s fileName
    string str_tar, str_name = fileName;
    string label[10] = {"solid", " ", "facet", "normal", "outer",
                 "loop", "vertex", "endloop", "endfacet",
                 "endsolid"};

    fileName_index = (int) str_name.rfind(".");
    str_name = str_name.erase(fileName_index, 4);
    fileName_index = (int) str_name.rfind("\\");
    str_name = str_name.erase(0, fileName_index + 1);
    label[1] = str_name;

    while(!file.eof())
    {
        file >> str_tar;
        if(str_tar == label[0]);
        else if (str_tar == label[1]);
        else if (str_tar == label[2]);
        else if (str_tar == label[3])
        {
            cnt = cnt1 = cnt2 = 3;
        }
        else if(str_tar == label[4])
            cnt = 0;
        else if(str_tar == label[5]);
        else if(str_tar == label[6])
        {
            cnt1--;
            cnt2 = 3;
        }
        else if(str_tar == label[7])
        {
            cnt1 = cnt2 = 0;
        }
        else if(str_tar == label[8])
            m_triPt.push_back(*temp_tri);
        else if(str_tar == label[9]);
        else if(cnt != 0)
        {
            --cnt;
            switch (2-cnt) {
            case 0:
                temp_tri->normal.x = atof(str_tar.c_str());
                break;
            case 1:
                temp_tri->normal.y = atof(str_tar.c_str());
                break;
            case 2:
                temp_tri->normal.z = atof(str_tar.c_str());
                break;
            default:
                break;
            }
        }
        else if(cnt1!=0 || cnt2!=0)
        {
            cnt2--;
            switch ((2 - cnt2)) {
            case 0:
                temp_tri->vertex[2 - cnt1].x = atof(str_tar.c_str());
                break;
            case 1:
                temp_tri->vertex[2 - cnt1].y = atof(str_tar.c_str());
                break;
            case 2:
                temp_tri->vertex[2 - cnt1].z = atof(str_tar.c_str());
                break;
            default:
                break;
            }
        }
    }

    file.close();
    delete temp_tri;
}

void ReadStl::readBinary(string fileName)
{
    int num = 0;
    float value = 0;
    ifstream file(fileName, ios::binary | ios::in);
    SimpleTriangle *temp_tri = new SimpleTriangle();

    file.seekg(80);
    file.read((char *)(&num), sizeof(int));

    for(int i=0; i<num; i++)
    {
        file.read((char *)(&value), sizeof(float));
        temp_tri->normal.x = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->normal.y = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->normal.z = value;

        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[0].x = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[0].y = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[0].z = value;

        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[1].x = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[1].y = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[1].z = value;

        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[2].x = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[2].y = value;
        file.read((char *)(&value), sizeof(float));
        temp_tri->vertex[2].z = value;

        m_triPt.push_back(*temp_tri);
        file.seekg(2, ios::cur);
    }

    file.close();
}
