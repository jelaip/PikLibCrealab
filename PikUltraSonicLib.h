#ifndef PikUltraSonicLib.h
#define PikUltraSonicLib.h 
#include <Arduino.h>

class PikUltraSonic
{
    public:
        PikUltraSonic(int _pinTrig, int _pinEcho);
        int trigPin;
        int echoPin;
        float GetDistanceCm();
        float GetDistanceInch();
};

#endif