#ifndef SORT_H
#define SORT_H

class Analyzer
{
public:

    Analyzer(const int data[], const int length, const int key);

    int linearSearch(const unsigned lc);
    int binarySearch(const unsigned lc);
    void selectionSort(int data[], const int length);

    void display(); // show results

private:

    void clear() {eq = 0; com = 0; inc = 0; elapsedTime = 0;} // must reset values for next analysis

    int *array;
    int length;
    int key;
    unsigned eq;    // number of assignments
    unsigned com;   // number of comparisons
    unsigned inc;   // number of increments
    unsigned loopCount;
    double elapsedTime;
};

#endif // SORT_H
