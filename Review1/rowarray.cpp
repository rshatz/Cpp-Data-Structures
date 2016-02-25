#include "rowarray.h"

#include <iostream>
#include <random>
#include <cstdlib>

RowArray::RowArray(const int size)
{
    validate(size);//to check if listSize is negative

    listSize = size;
    list = new int[size];

//    std::random_device rd;
//    static std::default_random_engine engine(rd());
//    std::uniform_int_distribution<int> dist(10, 99);
    std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0,99);

    for(int index = 0; index < size; index++)
    {
        list[index] = dist(mt);//(rand() % 90 + 10);
    }
}

RowArray::~RowArray()
{
    delete [] list;
}

void RowArray::validate(const int index)
{
    if (index < 0 || index >= listSize)
    {
        std::cout << "ERROR: INVALID SUBSCRIPT";
        exit(EXIT_FAILURE);
    }
}

int RowArray::getSize()
{
    return listSize;
}

int RowArray::getValue(int index)
{
    validate(index);
    return list[index];
}














