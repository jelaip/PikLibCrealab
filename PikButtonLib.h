#ifndef PikButtonLib.h
#define PikButtonLib.h
#include <Arduino.h>

class PikButton
{
    public:
        PikButton(int _pin);
        bool Value();
        int pin;
};

#endif