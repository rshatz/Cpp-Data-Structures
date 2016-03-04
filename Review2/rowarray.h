#ifndef ROWARRAY_H
#define ROWARRAY_H

#include "absrow.h"

class RowArray : public AbsRow
{
public:

    RowArray(const int rows);
    virtual ~RowArray();

    virtual int getValue(int index) const override;
    virtual int getSize() const override;

    void setValue(int row, int value);
};

#endif // ROWARRAY_H
