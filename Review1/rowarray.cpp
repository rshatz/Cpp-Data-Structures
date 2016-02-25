#include "rowarray.h"

#include <iostream>
#include <random>

RowArray::RowArray(const int rows, const int minimum, const int maximum)
{
    validateNumRows(rows);
    static int minRange = minimum;
    static int maxRange = maximum;

    listSize = rows;
    list = new int[rows];

    std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(minRange, maxRange);

    for(int index = 0; index < rows; index++)
    {
        list[index] = dist(mt);
    }
}

RowArray::~RowArray()
{
    delete [] list;
}

void RowArray::validateNumRows(const int numRows)
{
    if(numRows < 0)
    {
        std::cout << "ERROR: INVALID SUBSCRIPT";
        exit(EXIT_FAILURE);
    }
}

void RowArray::validateIndex(const int index)
{
    if(index < 0 || index >= listSize)
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
    validateIndex(index);
    return list[index];
}
