#ifndef TABLE_H
#define TABLE_H

#include "rowarray.h"
#include "abstable.h"

class Table : public AbsTable
{
public:

    Table(const int rows, const int cols);
    Table(Table &table);
    virtual ~Table();

    virtual int getRowSize() const override;
    virtual int getColSize() const override;
    virtual int getValue(int row, int col) const override;



    void setValue(int row, int col, int value) const;
};

#endif // TABLE_H
