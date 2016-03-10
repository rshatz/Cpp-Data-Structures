
#include "rowarray.h"
#include <cstdlib>

template <class T>
RowArray<T>::RowArray(const int rows)
{
    this->rowSize = rows;
    this->rowPntr = new int[rows];

    for(int index = 0; index < rows; index++)
    {
        this->rowPntr[index] = (rand() % 90) + 10;
    }
}

template <class T>
RowArray<T>::~RowArray()
{
    delete [] this->rowPntr;
}

template <class T>
void RowArray<T>::setValue(int row, int value)
{
    this->rowPntr[row] = value;
}

template <class T>
int RowArray<T>::getSize() const
{
    return this->rowSize;
}

template <class T>
T RowArray<T>::getValue(int index) const
{
    return this->rowPntr[index];
}
