
#include "addtable.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

template <class T>
void displayTable(T &table);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int numRows = 5;
    int numCols = 13;

    AddTable<float> table1(numRows, numCols);
    AddTable<float> table2(table1);
    AddTable<float> table3 = table1 + table2;

    // Print the tables

    std::cout << "Abstracted and Polymorphic Print Table 1 size is [row,col] = ["
            << numRows << "," << numCols <<"]";
    displayTable(table1);
    std::cout << "Copy Constructed Table 2 size is [row,col] = ["
            << numRows << "," << numCols <<"]";
    displayTable(table2);
    std::cout << "Operator Overloaded Table 3 size is [row,col] = ["
            << numRows << "," << numCols <<"]";
    displayTable(table3);

    //Exit Stage Right
    return 0;
}

template <class T>
void displayTable(T &table)
{
    std::cout << std::endl;
    for(int row=0;row<table.getRowSize();row++){
        for(int col=0;col<table.getColSize();col++){
            std::cout<<std::setw(4)<<table.getValue(row,col);
        }
        std::cout << std::endl;
    }
}
