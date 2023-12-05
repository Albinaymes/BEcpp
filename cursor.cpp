#include "Matrix8x8.h"
#include "Cursor.h"


//Matrix8x8 emptyMatrix;
Cursor::Cursor(Matrix8x8 matrix, int initialColumn) : Matrixx(matrix), column(initialColumn) {}
Cursor::Cursor() : Matrixx(), column(0) {}

void Cursor::moveLeft() {
    if (column > 0) {
        --column;
    }
}

void Cursor::moveRight() {
    const int maxColumn = 7;
    if (column < maxColumn) {
        ++column;
    }
}

int Cursor::getColumn() const {
    return column;
}

