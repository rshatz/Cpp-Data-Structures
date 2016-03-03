#ifndef ROWARRAY_H
#define ROWARRAY_H

#include "absrow.h"

class RowArray : public AbsRow
{
public:

    RowArray(const int rows, const int minimum = 0, const int maximum = 2147483647);
    virtual ~RowArray();

    virtual int getData(int index) const final;
    virtual int getSize() const final;

private:

    void validateIndex(const int index) const;//validate subscripts
    void validateNumRows(const int numRows) const;
};

#endif // ROWARRAY_H
