#ifndef BOARD_H
#define BOARD_H

#include "Matrix8x8.h" 
#include "Cursor.h"


class Board  {
public:
     Board(Matrix8x8& matrix, int initialColumn, Cursor& curseur);
     Board();
    ~Board(); 
    void PlayMove();
    void GameResult();// cette fonction change en fonction du resultat de la partie en cours, ou non, la valeur de GameState
    Matrix8x8 Mat;// public car je m'en sers dans le main
    int GameState ;  //0 si la partie est toujours en cours, 1 si il y a un gagnant
    
    
private :
     
    Cursor& Curs;
    int player ; // 1 quand c'est au player 1 de jouer, 2 quand c'est au player 2
    
    


   
};

#endif // BOARD_H