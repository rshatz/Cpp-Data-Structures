#include "table.h"

Table::Table(const int rows, const int cols)
{
    rowArray = new RowArray *[rows];

    for(int rowIndex = 0; rowIndex < getRowSize(); rowIndex++)
    {
        rowArray[rowIndex] = new RowArray(cols);
        for(int colIndex = 0; colIndex < getColSize(); colIndex++)
        {
            rowArray[rowIndex][colIndex] = 0;
        }
    }
}
