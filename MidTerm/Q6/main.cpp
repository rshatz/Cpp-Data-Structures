#include "Analyzer.h"

#include <iostream>
#include <ctime>
#include <cmath>

int* fillArray(const int arrSize)
{
    int* arr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % arrSize;
    }
    return arr;
}

int main()
{ 
    srand(static_cast<unsigned int>(time(0)));

    int size = 300;
    int key = size + 1; // set key to worst case which is when the element is not in the list
    int* arr = fillArray(size);

    Analyzer a(arr, size, key);
    a.selectionSort(arr, size);

    // Selection Sort
    std::cout << "Selection Sort Results:\n\n";

    // Linear Search
    std::cout << "Linear Search Results:\n\n";

    int p = 4;
    for (int i = 0; i < 4; i++) {
        a.linearSearch(pow(10, p));
        a.display();
        p++;
    }

    // Binary Search
    std::cout << "Binary Search Results:\n\n";

    p = 4;
    for (int i = 0; i < 4; i++) {
        a.binarySearch(pow(10, p));
        a.display();
        p++;
    }
}






