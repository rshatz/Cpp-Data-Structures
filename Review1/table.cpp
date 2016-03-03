#include "table.h"
#include "rowarray.h"

Table::Table(const int rows, const int cols)
{
    rowSize = rows;
    colSize = cols;

    table = new RowArray*[rows];// set number of rows in a table

    for(int rowindex = 0; rowindex < rows; rowindex++)
    {
        table[rowindex] = new RowArray(cols);// set number of columns in a table
    }
}

Table::~Table()
{
    delete []table;
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
    return table[row]->getValue(col);
}
