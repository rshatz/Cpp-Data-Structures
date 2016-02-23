#include "rowarray.h"

#include <iostream>
#include <cstdlib>

RowArray::RowArray(const int listSize)
{
    validate(listSize);//check if listSize is negative

    list = new int[listSize];
    numOfElements = listSize;

    for(int index = 0; index < listSize; index++)
        list[index] = 0;
}

void RowArray::validate(int index)
{
    if (index < 0 || index >= numOfElements)
    {
        std::cout << "ERROR: INVALID SUBSCRIPT";
        exit(EXIT_FAILURE);
    }
}

void RowArray::setValue(const int value, const int index)
{
    validate(index);
    list[index] = value;
}

int RowArray::getValue(int index)
{
    return list[index];
}














