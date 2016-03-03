#ifndef ROWARRAY_H
#define ROWARRAY_H

class RowArray
{
public:

    RowArray(const int rows);
    virtual ~RowArray();

    int getValue(int index) const;
    int getSize() const;

private:

    int *rowPntr;
    int rowSize;
};

#endif // ROWARRAY_H
