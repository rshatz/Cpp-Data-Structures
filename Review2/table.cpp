//#include "table.h"
//#include "rowarray.h"
//
//Table::Table(const int rows, const int cols)
//{
//    rowSize = rows;
//    colSize = cols;
//
//    table = new RowArray*[rows];// set number of rows in a table
//
//    for(int rowindex = 0; rowindex < rows; rowindex++)
//    {
//        table[rowindex] = new RowArray(cols);// set number of columns in a table
//    }
//}
//
//Table::Table(const Table &table)
//{
//    this->rowSize = table.getRowSize();
//    this->colSize = table.getColSize();
//
//    this->table = new RowArray*[rowSize];
//
//    for(int row = 0; row < rowSize; row++)
//    {
//        this->table[row] = new RowArray(colSize);
//
//        for(int col = 0; col < colSize; col++)
//        {
//            setValue(row, col, table.getValue(row, col));
//        }
//    }
//}
//
//Table::~Table()
//{
//    delete []table;
//}
//
//void Table::setValue(int row, int col, int value) const
//{
//    table[row]->setValue(col, value);
//}
//
//int Table::getRowSize() const
//{
//    return rowSize;
//}
//
//int Table::getColSize() const
//{
//    return colSize;
//}
//
//int Table::getValue(int row, int col) const
//{
//    return table[row]->getValue(col);
//}
