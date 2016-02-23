#ifndef TABLE_H
#define TABLE_H

#include "rowarray.h"

class Table
{
public:

    Table(const int rows, const int cols);

    int getRowSize(){return rowSize;}
    int getColSize(){return colSize;}
    int getData(const int row, const int col);

private:

    RowArray **rowArray;

    int rowSize;
    int colSize;
};

#endif // TABLE_H
