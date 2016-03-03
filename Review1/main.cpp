#include "rowarray.h"
#include "table.h"

#include <iostream>
#include <ctime>

void displayRow(RowArray *rowArray, const int perLine);
void displayCol(Table *table);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int numRows = 5;
    int numCols = 3;
    int perLine = 5;

    RowArray rowArray(numRows);
    displayRow(&rowArray, perLine);

    Table table(numRows, numCols);
    displayCol(&table);

    std::cout << std::endl;

    return 0;
}

void displayRow(RowArray *rowArray, const int perLine)
{
    for(int index = 0; index < rowArray->getSize(); index++)
    {
        std::cout << rowArray->getValue(index) << " ";

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
