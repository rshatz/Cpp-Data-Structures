#ifndef TABLE_H
#define TABLE_H

#include "abstable.h"
#include "rowarray.h"

template <class T>
class Table : public AbsTable<T>
{
public:

    Table(const int rows, const int cols);
    Table(const Table &table);
    virtual ~Table();

    virtual int getRowSize() const override;
    virtual int getColSize() const override;
    virtual T getValue(int row, int col) const override;

    void setValue(int row, int col, T value) const;

};

template <class T>
Table<T>::Table(const int rows, const int cols)
{
    this->rowSize = rows;
    this->colSize = cols;

    this->table = new RowArray<T>*[rows];// set number of rows in a table

    for (int rowindex = 0; rowindex < rows; rowindex++)
    {
        this->table[rowindex] = new RowArray<T>(cols);// set number of columns in a table
    }
}

template <class T>
Table<T>::Table(const Table &table)
{
    this->rowSize = table.getRowSize();
    this->colSize = table.getColSize();

    this->table = new RowArray<T>*[this->rowSize];

    for (int row = 0; row < this->rowSize; row++)
    {
        this->table[row] = new RowArray<T>(this->colSize);

        for (int col = 0; col < this->colSize; col++)
        {
            setValue(row, col, table.getValue(row, col));
        }
    }
}

template <class T>
Table<T>::~Table()
{
    delete [] this->table;
}

template <class T>
void Table<T>::setValue(int row, int col, T value) const
{
    this->table[row]->setValue(col, value);
}

template <class T>
int Table<T>::getRowSize() const
{
    return this->rowSize;
}

template <class T>
int Table<T>::getColSize() const
{
    return this->colSize;
}

template <class T>
T Table<T>::getValue(int row, int col) const
{
    return this->table[row]->getValue(col);
}

#endif // TABLE_H
