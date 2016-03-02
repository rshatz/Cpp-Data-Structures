#include "rowarray.h"
#include "table.h"

#include <iostream>

void displayRow(RowArray *rowArray, const int perLine);
void displayCol(Table *table);

int main()
{
    int numRows = 10;
    int numCols = 10;
    int perLine = 5;
    int min = 10;
    int max = 99;

    RowArray rowArray(numRows, min, max);
    displayRow(&rowArray, perLine);

    Table table(numRows, numCols);
    displayCol(&table);

    std::cout << std::endl;
}

void displayRow(RowArray *rowArray, const int perLine)
{
    for(int index = 0; index < rowArray->getSize(); index++)
    {
        std::cout << rowArray->getData(index) << " ";

        if(index % perLine == (perLine - 1))
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void displayCol(Table *table)
{
    for(int rowIndex = 0; rowIndex < table->getRowSize(); rowIndex++)
    {
        for(int colIndex = 0; colIndex < table->getColSize(); colIndex++)
        {
            std::cout << table->getData(rowIndex, colIndex) << " ";
        }
        std::cout << std::endl;
    }
}
