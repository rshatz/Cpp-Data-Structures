#include "SortAnalyzer.h"

#include <iostream>

int SortAnalyzer::linearSearch(const int data[], const int length, const int key)
{
    clear();
    begin = clock();
    for (unsigned i = 0; i < loopCount; i++) {

        eq++;  // i = 0
        for (int i = 0; i < length; i++) {

            com++; // i < length
            com++; // val == data[i]

            if (key == data[i]) {

                return data[i]; // success
            }
            inc++; // i++
        }
    }
    end = clock();
    elapsed = double(end - begin) / CLOCKS_PER_SEC;

    return -1; // failure
}

int SortAnalyzer::binarySearch(const int arr[], int length, const int key)
{
    clear();
    begin = clock();
    for (unsigned i = 0; i < loopCount; i++) {

        int low = 0;
        int mid = 0;
        int high = length;

        while (low <= high) {

            com++; // low <= high

            mid = static_cast<int>((low + high)/2);
            eq++;  // mid = mid = (low + high)/2

            if (key < arr[mid]) {
                com++; // key < arr[mid]

                high = mid - 1;
                eq++;  // high = mid -1
            }
            else if (arr[mid] < key) {
                com += 2; // arr[mid] < key

                low = mid + 1;
                eq++;  // low = mid + 1
            }
            else {
                com += 2;
                return arr[mid]; // success
            }
        }
    }
    end = clock();
    elapsed = double(end - begin) / CLOCKS_PER_SEC;

    return -1; // failure:
}

void SortAnalyzer::display()
{
    std::cout << "Number of equalities: " << eq
              << "\nNumber of increments: " << inc
              << "\nNumber of comparisons: " << com
              << "\nC Total: " << eq + inc + com
              << "\nTime: " << elapsed << "\n\n";
}
