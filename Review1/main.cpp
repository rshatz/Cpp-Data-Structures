#include "rowarray.h"
#include "table.h"

#include <iostream>
#include <ctime>

void displayRow(RowArray *rowArray);
void displayTable(Table *table);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int numRows = 5;
    int numCols = 13;

    RowArray rowArray(numRows);
    displayRow(&rowArray);

    Table table(numRows, numCols);
    displayTable(&table);

    std::cout << std::endl;

    return 0;
}

void displayRow(RowArray *rowArray)
{
    for(int index = 0; index < rowArray->getSize(); index++)
    {
        std::cout << rowArray->getValue(index) << std::endl;
    }
    std::cout << std::endl;
}

void displayTable(Table *table)
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
