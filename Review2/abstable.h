#ifndef ABSTABLE_H
#define ABSTABLE_H

#include "rowarray.h"

class AbsTable{

public:

    virtual int getRowSize()const = 0;
    virtual int getColSize()const = 0;
    virtual int getData(int,int)const = 0;

protected:

    RowArray **columns;

    int numRows;
    int numCols;

};

#endif // ABSTABLE_H
