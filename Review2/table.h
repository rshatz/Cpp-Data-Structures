#ifndef TABLE_H
#define TABLE_H

#include "abstable.h"

class Table : public AbsTable
{
public:

    Table(const int rows, const int cols);

    virtual ~Table();

    virtual int getRowSize() const final {return rowSize;}
    virtual int getColSize() const final {return colSize;}
    virtual getData(const int row, const int col) const final;
    //virtual setData(int , int , int);
};

#endif // TABLE_H
