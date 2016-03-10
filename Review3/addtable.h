#ifndef ADDTABLE_H
#define ADDTABLE_H

#include "Table.h"

template <class T>
class AddTable : public Table<T>
{

public:

    AddTable(int row, int col) : Table<T>(row, col){}
    AddTable operator+(const AddTable &);

};

template <class T>
AddTable<T> AddTable<T>::operator+(const AddTable<T> &right)
{
    AddTable temp(this->rowSize, this->colSize);

    for (int row = 0; row < this->rowSize; row++)
    {
        for (int col = 0; col < this->colSize; col++)
        {
            temp.setValue(row, col, (this->getValue(row, col) + right.getValue(row, col)));
        }
    }

    return temp;
}

#endif // ADDTABLE_H
