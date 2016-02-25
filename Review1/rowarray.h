#ifndef ROWARRAY_H
#define ROWARRAY_H

class RowArray
{
public:

    RowArray(const int rows, const int minimum = 0, const int maximum = 2147483647);
    virtual ~RowArray();

    int getValue(const int index);
    int getSize();

private:

    void validateIndex(const int index);//validate subscripts
    void validateNumRows(const int numRows);

    int *list;//pointer to array
    int listSize;//number of elements of array
};

#endif // ROWARRAY_H
