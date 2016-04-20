#ifndef SORT_H
#define SORT_H

class SortAnalyzer
{
public:

    SortAnalyzer(const unsigned lc)
        : eq(0)
        , com(0)
        , inc(0)
        , elapsedTime(0)
        , loopCount(lc){}

    int linearSearch(const int data[], const int length, const int key);
    int binarySearch(const int data[], const int length, const int key);

    void display(); // show results

private:

    void clear() {eq = 0; com = 0; inc = 0; elapsedTime = 0;} // must reset values for next analysis

    unsigned eq;    // number of assignments
    unsigned com;   // number of comparisons
    unsigned inc;   // number of increments
    double elapsedTime;
    unsigned loopCount;
};

#endif // SORT_H
