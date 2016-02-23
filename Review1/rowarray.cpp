#include "rowarray.h"

#include <iostream>
#include <cstdlib>

RowArray::RowArray(const int size)
{
    validate(size);//to check if listSize is negative

    listSize = size;
    list = new int[size];

    for(int index = 0; index < size; index++)
        list[index] = 0;
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

void RowArray::setValue(const int index, const int value)
{
    validate(index);
    list[index] = value;
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














