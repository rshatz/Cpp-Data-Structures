#include "rowarray.h"

#include <iostream>
#include <random>

#include "absrow.h"

RowArray::RowArray(const int rows)
{
    listSize = rows;
    list = new int[rows];

    std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(10, 100);

    for(int index = 0; index < rows; index++)
    {
        list[index] = dist(mt);
    }
}

RowArray::~RowArray()
{
    delete [] list;
}


int RowArray::getSize() const
{
    return listSize;
}

int RowArray::getData(int index) const
{
    return list[index];
}
