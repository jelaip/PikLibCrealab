#ifndef PikLedLib.h
#define PikLedLib.h 
#include <Arduino.h>
#if defined(ESP32)
  
#endif 


class PikLed
{
    public:
        PikLed(int _pin);
        void On();
        void Off();
        #if defined(ESP32)
        void Fade(int power,int canal);
        #else
        void Fade(int power);    
        #endif  
        int pin;
};

#endif