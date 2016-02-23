#include "rowarray.h"

#include <iostream>
#include <random>

int main()
{
    int numRows = 0;
    int perLine = 5;
    int minVal = 10;
    int maxVal = 99;

    std::cout << "Enter the number of rows: ";
    std::cin >> numRows;

    RowArray rowArray(numRows);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(minVal, maxVal);

    for(int index = 0; index < numRows; index++)
    {
        rowArray.setValue(dist(mt), index);

        std::cout << rowArray.getValue(index) << " ";

        if(index % perLine == (perLine - 1))
            std::cout << std::endl;
    }
}


