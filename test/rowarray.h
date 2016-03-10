#ifndef ROWARRAY_H
#define ROWARRAY_H

#include "absrow.h"

template <class T>
class RowArray : public AbsRow<T>
{
public:

    RowArray(const int rows);
    virtual ~RowArray();

    virtual T getValue(int index) const override;
    virtual int getSize() const override;

    void setValue(int row, int value);
};

#endif // ROWARRAY_H
