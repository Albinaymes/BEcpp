#ifndef MATRIX8X8_H
#define MATRIX8X8_H

#include <vector> 

class Matrix8x8 {
public:
    Matrix8x8();
    int getValue(int row, int col) const;
    void setValue(int row, int col, int value);
    void insertToken(int column, int player);
    
private:
    int rows;
    int columns;
    std::vector<std::vector<int>> matrix;
};

#endif // MATRIX8X8_H

