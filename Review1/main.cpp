#include "rowarray.h"
#include "table.h"

#include <iostream>
#include <random>

void fillRow(RowArray *rowArray, const int min, const int max);
void displayRow(RowArray *rowArray, const int perLine);

int main()
{
    int numRows = 0;
    int numCols = 0;
    int perLine = 5;
    int min = 10;
    int max = 99;

    std::cout << "Enter the number of rows: ";
    std::cin >> numRows;

    RowArray rowArray(numRows);

    fillRow(&rowArray, min, max);
    displayRow(&rowArray, perLine);
}

void fillRow(RowArray *rowArray, const int min, const int max)
{
    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist(min, max);

    for(int index = 0; index < rowArray->getSize(); index++)
    {
        rowArray->setValue(index, dist(engine));
    }
}

void displayRow(RowArray *rowArray, const int perLine)
{
    for(int index = 0; index < rowArray->getSize(); index++)
    {
        std::cout << rowArray->getValue(index) << " ";

        if(index % perLine == (perLine - 1))
            std::cout << std::endl;
    }
}

