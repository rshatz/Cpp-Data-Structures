#ifndef ROWARRAY_H
#define ROWARRAY_H

#include <cstdlib>
#include "absrow.h"

template <class T>
class RowArray : public AbsRow<T>
{
public:

    RowArray(const int rows);
    virtual ~RowArray();

    virtual T getValue(int index) const override;
    virtual int getSize() const override;

    void setValue(int row, T value);
};

template <class T>
RowArray<T>::RowArray(const int rows)
{
    this->rowSize = rows;
    this->rowPntr = new T[rows];

    for (int index = 0; index < rows; index++)
    {
        this->rowPntr[index] = (rand() % 90) + 10;
    }
}

template <class T>
RowArray<T>::~RowArray()
{
    delete[] this->rowPntr;
}

template <class T>
void RowArray<T>::setValue(int row, T value)
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

#endif // ROWARRAY_H
