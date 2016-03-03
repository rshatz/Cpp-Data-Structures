#ifndef ADDTABLE_H
#define ADDTABLE_H

#include "table.h"

class AddTable : public Table{

public:

    AddTable(unsigned int r, unsigned int c) : Table(r, c){}
    AddTable operator+(const AddTable &);

};

#endif // ADDTABLE_H
