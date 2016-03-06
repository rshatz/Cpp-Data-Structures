#include "addtable.h"

AddTable AddTable::operator+(const AddTable &right)
{
    AddTable temp(this->rowSize, this->colSize);

    for(int row = 0; row < this->rowSize; row++)
    {
        for(int col = 0; col < this->colSize; col++)
        {
            temp.setValue(row, col, (this->getValue(row, col) + right.getValue(row, col)));
        }
    }

    return temp;
}
