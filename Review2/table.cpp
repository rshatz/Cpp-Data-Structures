#include "table.h"
#include "rowarray.h"


#include <iostream>
Table::Table(const int rows, const int cols)
{
    rowSize = rows;
    colSize = cols;

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

//void Table::setData(int row, int col, int data)
//{

//}

int Table::getData(const int row, const int col) const
{
    return columns[row]->getData(col);
}
