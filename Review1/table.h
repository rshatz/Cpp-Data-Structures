#ifndef TABLE_H
#define TABLE_H

#include "rowarray.h"

class Table
{
public:

    Table(const int rows, const int cols);
    virtual ~Table();

    int getRowSize(){return numRows;}
    int getColSize(){return numCols;}
    int getData(const int row, const int col);

private:

    RowArray **columns;

    int numRows;
    int numCols;
};

#endif // TABLE_H
