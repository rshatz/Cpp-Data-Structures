#ifndef TABLE_H
#define TABLE_H

#include "abstable.h"

class Table : public AbsTable
{
public:

    Table(const int rows, const int cols);
    virtual ~Table();

    int getRowSize() const override {return numRows;}
    int getColSize() const override {return numCols;}
    int getData(const int row, const int col) const override;
};

#endif // TABLE_H
