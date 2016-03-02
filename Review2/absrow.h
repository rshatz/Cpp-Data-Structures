#ifndef ABSROW_H
#define ABSROW_H


class AbsRow{

public:

    virtual int getSize()const = 0;
    virtual int getData(int)const = 0;

protected:

    int *list;//pointer to array
    int listSize;//number of elements of array
};

#endif // ABSROW_H
