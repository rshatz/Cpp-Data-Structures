#include "rowarray.h"
#include "table.h"

#include <iostream>

void displayRow(RowArray *rowArray, const int perLine);
void displayTable(Table *table);

int main()
{
    int numRows = 5;
    int numCols = 10;
    int perLine = 5;

    RowArray rowArray(numRows);
    displayRow(&rowArray, perLine);

    Table table(numRows, numCols);
    displayTable(&table);

    std::cout << std::endl;

//    Table table2(table);
//    displayTable(&table2);

    return 0;
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
