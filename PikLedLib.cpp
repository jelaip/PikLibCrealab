#include <Arduino.h>
#include <PikLedLib.h>
PikLed::PikLed(int _pin){
    pin = _pin;
    pinMode(pin , OUTPUT);
}
void PikLed::On(){
    digitalWrite(pin, HIGH);
}
void PikLed::Off(){
    digitalWrite(pin, LOW);
}
#if defined(ESP32)
void PikLed::Fade(int power,int canal){
    power =map(power,0,100,0,255);
    ledcSetup(canal, 5000, 8);
    ledcAttachPin(pin, canal);
    ledcWrite(canal, power);
}
#else
void PikLed::Fade(int power){
    power =map(power,0,100,0,255);
    analogWrite(pin, power);
}       
#endif    
