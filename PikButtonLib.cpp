#include <Arduino.h>
#include <PikButtonLib.h>
PikButton::PikButton(int _pin){
    pin = _pin;
    pinMode(pin , INPUT);
}
bool PikButton::Value(){
    digitalRead(pin);
}