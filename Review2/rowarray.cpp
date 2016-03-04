#include "rowarray.h"
#include <cstdlib>

RowArray::RowArray(const int rows)
{
    rowSize = rows;
    rowPntr = new int[rows];

    for(int index = 0; index < rows; index++)
    {
        rowPntr[index] = (rand() % 90) + 10;
    }
}

RowArray::~RowArray()
{
    delete [] rowPntr;
}

void RowArray::setValue(int row, int value)
{
    rowPntr[row] = value;
}

int RowArray::getSize() const
{
    return rowSize;
}

int RowArray::getValue(int index) const
{
    return rowPntr[index];
}
