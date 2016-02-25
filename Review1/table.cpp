#include "table.h"
#include "rowarray.h"
#include <iostream>

Table::Table(const int rows, const int cols)
{
    numRows = rows;
    numCols = cols;

    rowArray = new RowArray*[rows];

    for(int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        rowArray[rowIndex] = new RowArray(cols);
    }
}

Table::~Table()
{
    delete [] rowArray;
}

int Table::getData(const int row, const int col)
{
    return rowArray[row]->getValue(col);
}
