#ifndef ROWARRAY_H
#define ROWARRAY_H

class RowArray
{
public:

    RowArray(const int listSize);
    ~RowArray(){delete [] list;}

    void setValue(const int value, const int index);//set a user defined value at specified index

    int getValue(const int index);

private:

    void validate(int index);//validate subscripts

    int *list;//pointer to array
    int numOfElements;//number of elements of array
};

#endif // ROWARRAY_H
