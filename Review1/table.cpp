#include "table.h"
#include "rowarray.h"

Table::Table(const int rows, const int cols)
{
    numRows = rows;
    numCols = cols;

    columns = new RowArray*[rows];

    for(int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        columns[rowIndex] = new RowArray(cols);
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

int Table::getData(const int row, const int col)
{
    return columns[row]->getValue(col);
}
