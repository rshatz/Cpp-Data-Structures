#ifndef SORT_H
#define SORT_H

class Analyzer
{
public:

    Analyzer()
      : eq(0)
      , com(0)
      , inc(0)
      , swp(0)
      , elapsedTime(0)
      , loopCount(0) {}

    int linearSearch(int data[], const int length, const int key);
    int binarySearch(int data[], const int length, const int key);
    void selectionSort(int data[], const int length);

//    int linearAnalyzer(const int data[], const int length, const int key);
//    int binaryAnalyzer(const int data[], const int length, const int key);
//    void selectionAnalyzer(int data[], const int length);

    void setLoopCount(const int lc) {loopCount = lc;}
    void display(); // show results

private:

    void clear() {eq = 0; com = 0; inc = 0;
                  swp = 0, elapsedTime = 0;} // must reset values for next analysis

    unsigned eq;    // number of assignments
    unsigned com;   // number of comparisons
    unsigned inc;   // number of increments
    unsigned swp;   // number of swaps

    double elapsedTime;
    int loopCount;
};

#endif // SORT_H
