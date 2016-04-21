#include "Analyzer.h"

#include <iostream>
#include <ctime>
#include <cmath>

void fillArray(int arr[], const int arrSize)
{
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % arrSize;
    }
}

void print(int arr[], const int arrSize)
{
    std::cout << "---------\n";
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << "\n";
    }
}

int main()
{ 
    srand(static_cast<unsigned int>(time(0)));

    Analyzer a;

    // Selection Sort
    std::cout << "-----------------------\n"
              << "Selection Sort Results:\n"
              << "-----------------------\n";

    int sortSize = 5000;
    for (int i = 0; i < 4; i++) {

        int* sortArr = new int[sortSize];

        fillArray(sortArr, sortSize);
        a.selectionSort(sortArr, sortSize);
        a.display();

        sortSize *= 2;
        delete[] sortArr;
    }

    // Linear Search
    std::cout << "-----------------------\n"
              << "Linear Search Results:\n"
              << "-----------------------\n";

    int size = 300;
    int key = size + 1; // set key to worst case which is when the element is not in the list
    int* arr = new int[size];

    int expo = 4;
    for (int i = 0; i < 4; i++) {
        a.setLoopCount(pow(10, expo));
        a.linearSearch(arr, size, key);
        a.display();
        expo++;
    }

    // Binary Search
    std::cout << "-----------------------\n"
              << "Binary Search Results:\n"
              << "-----------------------\n";

    expo = 4;
    for (int i = 0; i < 4; i++) {
        a.setLoopCount(pow(10, expo));
        a.binarySearch(arr, size, key);
        a.display();
        expo++;
    }
}
