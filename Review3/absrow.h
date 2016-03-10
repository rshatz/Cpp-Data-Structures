#ifndef ABSROW_H
#define ABSROW_H

template <class T>
class AbsRow
{
public:

    virtual int getSize()const = 0;
    virtual T getValue(int index)const = 0;

protected:

    T *rowPntr;
    int rowSize;
};

#endif // ABSROW_H
