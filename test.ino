#include "joystick.h"
#include <Arduino.h>
#include "Matrix8x8.h"
#include "cursor.h"
#include "LedButtun.h"
#include "TouchSensor.h"
#include "Board.h"


Matrix8x8 Matrix1;
Cursor Cursor1(Matrix1, 0);
LedButtun ledButtun1;
joystick Joystick1;
Board Board1(Matrix1, 0, Cursor1);
bool gameIsOver = false; // Variable de contrôle pour indiquer si le jeu est terminé


void setup() {
  Serial.begin(9600);
  pinMode(D5, INPUT);
  pinMode(D3, OUTPUT);
  digitalWrite(D3, LOW); // Ensure the LED is initially off
}

void loop() {

  if (!gameIsOver) { // Exécute seulement si le jeu n'est pas terminé

  if (Joystick1.directionJoy() == 1) {
    Cursor1.moveRight();
  }
  if (Joystick1.directionJoy() == 2) {
    Cursor1.moveLeft();
  }
  if (ledButtun1.readValue()==0){
    Board1.PlayMove();
    for (int row = 0; row < 8; ++row) {
    // Boucle pour parcourir toutes les colonnes
    for (int col = 0; col < 8; ++col) {
        // Utilise la fonction getValue pour obtenir la valeur à la position actuelle
        int value = Board1.Mat.getValue(row, col);

        // Affichez la valeur
        Serial.print(value);
        Serial.print(" ");
    }

    // Saut de ligne entre les lignes pour une meilleure lisibilité
    Serial.println();
}
// Saut de ligne supplémentaire à la fin pour une meilleure présentation
Serial.println();
Board1.GameResult();


}
Serial.println(Cursor1.getColumn());
if (Board1.GameState==1){
  Serial.println("GAME OVER");
  gameIsOver = true;

}
  }


  
  delay(500); // Délai pour éviter une lecture trop fréquente
}


