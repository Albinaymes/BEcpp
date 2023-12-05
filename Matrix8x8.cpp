#include "Matrix8x8.h"
#include <Arduino.h>

Matrix8x8::Matrix8x8() : rows(8), columns(8), matrix(rows, std::vector<int>(columns, 0)) {}

int Matrix8x8::getValue(int row, int col) const {
    return matrix[row][col];
}

void Matrix8x8::setValue(int row, int col, int value) {
    matrix[row][col] = value;
}

void Matrix8x8::insertToken(int column, int player) {
    // cherche la première case vide (où la valeur est 0) dans la colonne
    Serial.print("Inserting token in column ");
    Serial.println(column);
    for (int row = rows - 1; row >= 0; --row) {
        if (matrix[row][column] == 0) {
            // Place le jeton du joueur dans la case vide
            matrix[row][column] = player;
            Serial.println("Token inserted successfully");
            break; // Quitte la boucle après avoir placé le jeton
        }
    }
}



