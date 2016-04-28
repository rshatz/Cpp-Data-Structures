#include "Analyzer.h"

#include <iostream>
#include <ctime>

void Analyzer::startTime() {
    //start = 0;
    start = clock();
}

void Analyzer::endTime() {
    end = clock();
}

int Analyzer::linearSearch(int data[], const int length, const int key)
{
    clear(); // reset values to 0
    arraySize = length;

    opp++;
    for (int i = 0; i < length; i++) {

        if (key == data[i]) {
            return data[i]; // success
        }
        opp += 3;
    }

    return -1; // failure
}

void Analyzer::selectionSort(int data[], const int length)
{
    opp++;
    for (int i = 0,j,least; i < length - 1; i++) {

        opp += 2;
        for (j = i + 1, least = i; j < length; j++) {
            opp += 2;
            if (data[j] < data[least]) {
                opp++;
                least = j;
            }
        }
        std::swap(data[least],data[i]);
        opp++;
    }
}

int Analyzer::binarySearch(int data[], const int length, const int key)
{
    clear(); // reset values to 0
    arraySize = length;

    int low = 0;
    int mid = 0;
    int high = length;

    selectionSort(data, length);
    while (low <= high) {
        opp += 2;

        mid = static_cast<int>((low + high)/2);
        opp++;  // mid = mid = (low + high)/2

        if (key < data[mid]) {
            high = mid - 1;
            opp += 2;
        }
        else if (data[mid] < key) {
            low = mid + 1;
            opp += 3;
        }
        else {
            opp += 2;
            return data[mid]; // success
        }
    }

    return -1; // failure:
}

float Analyzer::pow(float base, int power) {

    if (power != base) {
        power /= 2;
        pow(base, power);
    }
    return base;
}

void Analyzer::display()
{
    std::cout << "\nArray Size: " << arraySize
              << "\nC Total: " << opp
              << "\nTime: " << double(end - start) / CLOCKS_PER_SEC << "\n\n";
}
