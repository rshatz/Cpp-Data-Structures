#include "SortAnalyzer.h"

#include <iostream>
#include <ctime>

using namespace std;

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

    SortAnalyzer sa(100000000);

    sa.linearSearch(arr, size, key);
    sa.display();
    sa.binarySearch(arr, size, key);
    sa.display();
}






