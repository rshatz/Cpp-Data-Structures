#include "table.h"
#include "rowarray.h"

Table::Table(const int rows, const int cols)
{
    rowSize = rows;
    colSize = cols;

    columns = new RowArray*[cols];

    for(int col = 0; col < cols; col++)
    {
        columns[col] = new RowArray(rows);
    }
}

Table::~Table()
{
    for(int col = 0; col < getColSize(); col++)
    {
        delete columns[col];
    }
    delete []columns;
}

int Table::getRowSize() const
{
    return rowSize;
}

int Table::getColSize() const
{
    return colSize;
}

int Table::getData(int row, int col) const
{
    return columns[col]->getValue(row);
}
