#include "Analyzer.h"

#include <iostream>
#include <ctime>
#include <cmath>

void fillArray(int arr[], const int arrSize);
void print(int arr[], const int arrSize);

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
    a.setLoopCount(1);

    int size = 100000;
    int key = size + 1; // Set key to be outside the range.
                        // The key is not in the list and forces -1 to be retuned
    int exponent = 1;

    int* lineArr = new int[size];
   // fillArray(lineArr, size); // Fill the array with random digits.
                              // The size represents the range of possible numbers in the array.
                              // However, the key is set to be outside of the range and therefore is
                              // never found. This is the worst case scenario.
    // Linear Search
    int loopCount = 100;
    for (int i = 0; i < 4; i++) {
        fillArray(lineArr, size);
        //a.setLoopCount(loopCount);//pow(10, exponent));
        a.linearSearch(lineArr, size, key);
        std::cout << "-------------------------\n"
                  << "Linear Search " << i + 1 << " Results:\n"
                  << "-------------------------\n";
        a.display();
        exponent++;
        loopCount *= 2;
    }
    delete[] lineArr;

    // Binary Search with selection sort
    int* binArray = new int[size];
    exponent = 1;
    loopCount = 100;
    for (int i = 0; i < 4; i++) {

        fillArray(binArray, size); // Fill the array with new random digits.

        //a.setLoopCount(loopCount);//pow(10, exponent));
        a.binarySearch(binArray, size, key-1);
        std::cout << "-------------------------\n"
                  << "Binary Search " << i + 1  << " Results:\n"
                  << "-------------------------\n";
        a.display();
        exponent++;
        loopCount *= 2;
    }
    delete[] binArray;
}
