#ifndef ABSTABLE_H
#define ABSTABLE_H

#include "rowarray.h"

class AbsTable
{
public:

    virtual int getRowSize() const = 0;
    virtual int getColSize() const = 0;
    virtual int getValue(int row, int col) const = 0;

protected:

    RowArray **table;

    int rowSize;
    int colSize;
};

#endif // ABSTABLE_H
