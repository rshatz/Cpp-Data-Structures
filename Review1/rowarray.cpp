#include "rowarray.h"

#include <iostream>
#include <cstdlib>
#include <random>
RowArray::RowArray(const int size)
{
    //validate(size);//to check if listSize is negative

    listSize = size;
    this->list = new int[size];

    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist(10, 99);

    for(int index = 0; index < size; index++)
    {
        list[index] = dist(engine);
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
    //validate(index);
    return list[index];
}














