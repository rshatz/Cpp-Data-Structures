#ifndef ABSROW_H
#define ABSROW_H

class AbsRow
{
public:

    virtual int getSize()const = 0;
    virtual int getValue(int index)const = 0;

protected:

    int *rowPntr;
    int rowSize;
};

#endif // ABSROW_H
