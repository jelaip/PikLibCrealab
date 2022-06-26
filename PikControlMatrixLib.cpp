#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "PikControlMatrixLib.h"
#define NUMPIXELS 64

PikControlMatrix8x8::PikControlMatrix8x8(int _pin){
    pin = _pin;
    pixels = new Adafruit_NeoPixel(NUMPIXELS, pin, NEO_GRB + NEO_KHZ800);
    pixels->begin();
    pixels->setBrightness(2);
}

int PikControlMatrix8x8::Convert(int x, int y){
  if(x>7||x<0||y>7||y<0) return -1;
  return 7+8*x - y;
}

void PikControlMatrix8x8::GenerateSquarre(int x, int y, int taille, int r,int g,int b){
    for(int i = 0; i < taille; i++ ){
      pixels->setPixelColor(PikControlMatrix8x8::Convert(x+i,y),pixels->Color(r,g,b));
      pixels->setPixelColor(PikControlMatrix8x8::Convert(x+taille-1,y+i), pixels->Color(r,g,b));
      pixels->setPixelColor(PikControlMatrix8x8::Convert(x+taille-1-i,y+taille-1), pixels->Color(r,g,b));
      pixels->setPixelColor(PikControlMatrix8x8::Convert(x,y+taille-1-i), pixels->Color(r,g,b));
    }
    pixels->show();
}

void PikControlMatrix8x8::SetPixelByCoord(int x, int y, int r,int g,int b){
    pixels->setPixelColor(PikControlMatrix8x8::Convert(x,y), pixels->Color(r,g,b));
    pixels->show();
}

void PikControlMatrix8x8::Clear(){
    pixels->clear();
    pixels->show();
}
