#include "Analyzer.h"

#include <iostream>
#include <ctime>

Analyzer::Analyzer(const int data[], const int length, const int key)
    : length(length)
    , key(key)
    , eq(0)
    , com(0)
    , inc(0)
    , loopCount(0)
    , elapsedTime(0)
{
    array = new int[length];
    for (int i = 0; i < length; i++) {
        array[i] = data[i];
    }
}

void Analyzer::selectionSort(int data[], const int length)
{
    for (int i = 0,j,least; i < length - 1; i++) {
        for (j = i + 1, least = i; j < length; j++) {
            if (data[j] < data[least]) {
                least = j;
            }
        }
        std::swap(data[least],data[i]);
    }
}

int Analyzer::linearSearch(const unsigned lc)
{
    clear();
    loopCount = lc;
    clock_t begin = clock();
    for (unsigned i = 0; i < loopCount; i++) {

        eq++;  // i = 0
        for (int i = 0; i < length; i++) {

            com++; // i < length
            com++; // val == data[i]

            if (key == array[i]) {

                return array[i]; // success
            }
            inc++; // i++
        }
    }
    clock_t end = clock();
    elapsedTime = double(end - begin) / CLOCKS_PER_SEC;

    return -1; // failure
}

int Analyzer::binarySearch(const unsigned lc)
{
    clear();
    loopCount = lc;

    clock_t begin = clock();
    for (unsigned i = 0; i < loopCount; i++) {

        int low = 0;
        int mid = 0;
        int high = length;

        while (low <= high) {

            com++; // low <= high

            mid = static_cast<int>((low + high)/2);
            eq++;  // mid = mid = (low + high)/2

            if (key < array[mid]) {
                com++; // key < arr[mid]

                high = mid - 1;
                eq++;  // high = mid -1
            }
            else if (array[mid] < key) {
                com += 2; // arr[mid] < key

                low = mid + 1;
                eq++;  // low = mid + 1
            }
            else {
                com += 2;
                return array[mid]; // success
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
              << "\nC Total: " << eq + inc + com
              << "\nTime: " << elapsedTime << "\n\n";
}
