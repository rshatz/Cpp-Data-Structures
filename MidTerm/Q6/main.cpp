#include "Analyzer.h"
#include "listvector.h"

#include <iostream>
#include <ctime>

void fillArray(int arr[], const int arrSize)
{
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand();
    }
}

void print(int arr[], const int arrSize)
{
    std::cout << "------------------------------------\n";
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << "\n";
    }
    std::cout << "------------------------------------\n";
}

int main()
{ 
    srand(static_cast<unsigned int>(time(0)));

    Analyzer a;
    ListVector<int> lv;
    lv.push_back(12);

    int size = 50000;
    int key = -1; // key is set to not be in list. This is to test for worst case

    // Linear Search
    for (int i = 0; i < 4; i++) {

        int* lineArr = new int[size];

        fillArray(lineArr, size);
        a.linearSearch(lineArr, size, key);
        std::cout << "-------------------------\n"
                  << " Linear Search " << i + 1 << " Results:\n"
                  << "-------------------------\n";
        a.display();
        size *= 2;

        delete[] lineArr;
    }

    // Binary Search with selection sort
    size = 5000;
    for (int i = 0; i < 4; i++) {

        int* binArray = new int[size];

        fillArray(binArray, size);
        a.binarySearch(binArray, size, key);
        std::cout << "-------------------------\n"
                  << " Binary Search " << i + 1  << " Results:\n"
                  << "-------------------------\n";
        a.display();
        size *= 2;

        delete[] binArray;
    }
}
