#ifndef SORT_H
#define SORT_H

#include <ctime>

class Analyzer
{
public:

    Analyzer()
      : opp(0)
      , arraySize(0)
      , elapsedTime(0) {}

    int linearSearch(int data[], const int length, const int key);
    int binarySearch(int data[], const int length, const int key);
    void selectionSort(int data[], const int length);
    void optVectSort(const int& v);
    float pow(float base, int power);

    void display(); // show results
    void startTime();
    void endTime();

private:

    struct Node
    {
        Node(int v)
           : next(nullptr)
           , value(v) {}
        Node *next;
        int value;
    };

    void clear() {opp = 0, elapsedTime = 0; arraySize = 0;} // must reset values for next analysis

    unsigned opp;
    int arraySize;
    clock_t start;
    clock_t end;
    double elapsedTime;
};

#endif // SORT_H
