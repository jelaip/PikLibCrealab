#ifndef PikAnalogInLib.h
#define PikAnalogInLib.h
#include <Arduino.h>

class PikAnalogIn
{
    public:
        PikAnalogIn(int _pin);
        int Value();
        int pin;
};

#endif