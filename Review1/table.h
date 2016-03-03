#ifndef TABLE_H
#define TABLE_H

#include "rowarray.h"

class Table
{
public:

    Table(const int rows, const int cols);
    virtual ~Table();

    int getRowSize() const;
    int getColSize() const;
    int getData(int row, int col) const;

private:

    RowArray **columns;

    int rowSize;
    int colSize;
};

#endif // TABLE_H
