#include <Arduino.h>
#include <PikControlMatrixLib.h>

PikControlMatrix8x8 matrix(4);

void setup(){
  matrix.Clear();
  matrix.GenerateSquare(1 ,1,6,250,10,10);
  for(int i =0; i<8; i++){
    matrix.SetPixelByCoord(i,i,0,250,0);
    matrix.SetPixelByCoord(7-i,i,0,250,0);
    delay(500);
  }
}
void loop() {
  
}