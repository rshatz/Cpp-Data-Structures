#include "Analyzer.h"
#include "ListVector.h"
#include "OptimizedVector.h"

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



    // Linear Search
    int size = 5000;
    int key = -1; // key is set to not be in list. This is to test for worst case
    for (int i = 0; i < 4; i++) {

        int* lineArr = new int[size];

        fillArray(lineArr, size);
        a.startTime();
        a.linearSearch(lineArr, size, key);
        a.endTime();
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
        a.startTime();
        a.binarySearch(binArray, size, key);
        a.endTime();
        std::cout << "-------------------------\n"
                  << " Binary Search " << i + 1  << " Results:\n"
                  << "-------------------------\n";
        a.display();
        size *= 2;

        delete[] binArray;
    }

    // Optimized Vector
    size = 5000;
    for (int i = 0; i < 4; i++) {
        a.startTime();
        OptimizedVector<int> ov;
        for (int j = 0; j < size; j++) {
            ov.insert(rand());
        }
        a.endTime();
        std::cout << "-------------------------\n"
                  << " Optimized Vector " << i + 1 << " Results:\n"
                  << "-------------------------\n";
        a.display();
        std::cout << "Number of operations: " << ov.getOp() << "\n";
        size *= 2;
    }

    // List Vector
    size = 5000;
    for (int i = 0; i < 4; i++) {
        a.startTime();
        ListVector<int> lv;
        for (int j = 1; j < size; j++) {
            lv.sorted_push(rand());
        }
        a.endTime();
        std::cout << "-------------------------\n"
                  << " List Vector " << i + 1 << " Results:\n"
                  << "-------------------------\n";
        a.display();
        std::cout << "Number of operations: " << lv.getOp() << "\n";
        size *= 2;
    }
}
