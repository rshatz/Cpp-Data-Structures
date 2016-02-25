#ifndef ROWARRAY_H
#define ROWARRAY_H

#include <random>

class RowArray
{
public:

    RowArray(const int size);
    ~RowArray();

    int getValue(const int index);
    int getSize();

private:

    static std::default_random_engine re;
    void validate(const int index);//validate subscripts

    int *list;//pointer to array
    int listSize;//number of elements of array
};

#endif // ROWARRAY_H
