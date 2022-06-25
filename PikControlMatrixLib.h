#ifndef PikControlMatrixLib.h
#define PikControlMatrixLib.h
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


class PikControlMatrix8x8
{
    public:
        Adafruit_NeoPixel *pixels;
        PikControlMatrix8x8(int _pin);
        int Convert(int x,int y);
        void GenerateSquarre(int x, int y, int taille, int color);
        void SetPixelByCoord(int x, int y, int color);
        void Clear();
        int pin;

};

#endif
