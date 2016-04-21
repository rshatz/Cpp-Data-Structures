#include "Analyzer.h"

#include <iostream>
#include <ctime>

void Analyzer::selectionSort(int data[], const int length)
{
    clock_t begin = clock();
    eq++; // i = 0
    for (int i = 0,j,least; i < length - 1; i++) {

        eq++; // j = i +1
        eq++; // least = i
        for (j = i + 1, least = i; j < length; j++) {
            com++; // j < length
            com++; // data[j] < data[least]
            if (data[j] < data[least]) {
                eq++; // least = j
                least = j;
            }
        }
        swp++; // std::swap(data[least],data[i]);
        std::swap(data[least],data[i]);
    }
    clock_t end = clock();
    elapsedTime = double(end - begin) / CLOCKS_PER_SEC;
}

int Analyzer::linearSearch(const int data[], const int length, const int key)
{
    clear(); // reset values to 0

    clock_t begin = clock();
    for (int loop = 0; loop < loopCount; loop++) {// for loop not part of linear search

        eq++;  // i = 0
        for (int i = 0; i < length; i++) { // begin linear search

            com++; // i < length
            com++; // val == data[i]

            if (key == data[i]) {

                return data[i]; // success
            }
            inc++; // i++
        }
    }
    clock_t end = clock();
    elapsedTime = double(end - begin) / CLOCKS_PER_SEC;

    return -1; // failure
}

int Analyzer::binarySearch(const int data[], const int length, const int key)
{
    clear(); // reset values to 0

    clock_t begin = clock();
    for (int i = 0; i < loopCount; i++) {

        int low = 0;
        int mid = 0;
        int high = length;

        while (low <= high) {

            com++; // low <= high

            mid = static_cast<int>((low + high)/2);
            eq++;  // mid = mid = (low + high)/2

            if (key < data[mid]) {
                com++; // key < arr[mid]

                high = mid - 1;
                eq++;  // high = mid -1
            }
            else if (data[mid] < key) {
                com += 2; // arr[mid] < key

                low = mid + 1;
                eq++;  // low = mid + 1
            }
            else {
                com += 2;
                return data[mid]; // success
            }
        }
    }
    clock_t end = clock();
    elapsedTime = double(end - begin) / CLOCKS_PER_SEC;

    return -1; // failure:
}

void Analyzer::display()
{
    std::cout << "Loop Count: " << loopCount
              << "\nNumber of equalities: " << eq
              << "\nNumber of increments: " << inc
              << "\nNumber of comparisons: " << com
              << "\nNumber of swaps: " << swp
              << "\nC Total: " << eq + inc + com + swp
              << "\nTime: " << elapsedTime << "\n\n";
}
