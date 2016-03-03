#ifndef ROWARRAY_H
#define ROWARRAY_H

#include "absrow.h"

class RowArray : public AbsRow
{
public:

    RowArray(const int rows);
    virtual ~RowArray();

    virtual int getData(int index) const final;
    virtual int getSize() const final;
    void setData(int col, int data);

private:


};

#endif // ROWARRAY_H
