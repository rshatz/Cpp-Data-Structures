#include "SortAnalyzer.h"

#include <iostream>
#include <cmath>

int* fillArray(const int arrSize)
{
    int* arr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main()
{ 
    int size = 300;
    int key = size + 1; // worst case is when element is not found
    int* arr = fillArray(size);

    SortAnalyzer sa(arr, size, key);

    std::cout << "Linear Search Results:\n\n";

    int p = 4;
    for (int i = 0; i < 4; i++) {
        sa.linearSearch(pow(10, p));
        sa.display();
        p++;
    }

    std::cout << "Binary Search Results:\n\n";

    p = 4;
    for (int i = 0; i < 4; i++) {
        sa.binarySearch(pow(10, p));
        sa.display();
        p++;
    }
}






