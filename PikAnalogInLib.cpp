#include <Arduino.h>
#include <PikAnalogInLib.h>
PikAnalogIn::PikAnalogIn(int _pin){
    pin = _pin;
    //pinMode(pin , INPUT);
}
int PikAnalogIn::Value(){
    int value; 
    #if defined(ESP32)
    value =map(analogRead(pin),0,4095,0,100);
    #else
    value =map(analogRead(pin),0,1024,0,100);
    #endif 
    return value;
}



