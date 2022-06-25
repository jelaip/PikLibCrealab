#include <Arduino.h>
#include <PikMotorL298NLib.h>
PikMotorL298N::PikMotorL298N(int _pinIn1,int _pinIn2,int _pinIn3,int _pinIn4,int _pinEnA,int _pinEnB){
    pinIn1 = _pinIn1;
    pinIn2 = _pinIn2;
    pinIn3 = _pinIn3;
    pinIn4 = _pinIn4;
    pinEnA = _pinEnA;
    pinEnB = _pinEnB;
    int pins[6] ={pinIn1,pinIn2,pinIn3,pinIn4,pinEnA,pinEnB};
    for(int i = 0; i<6; i++) pinMode(pins[i], OUTPUT);
    #if defined(ESP32)
        ledcSetup(15, 5000, 8);
        ledcAttachPin(pinEnA, 15);
        ledcSetup(14, 5000, 8);
        ledcAttachPin(pinEnB, 14); 
    #endif 
}
void PikMotorL298N::Forward(int power){
    power =map(power,0,100,0,255);
    PikMotorL298N::RunMotor(true,true);
    PikMotorL298N::RunMotor(false,true);
    #if defined(ESP32)
        ledcWrite(14, power);
        ledcWrite(15, power);
    #else
        analogWrite(pinEnA,power);
        analogWrite(pinEnB,power);
    #endif 
    
}
void PikMotorL298N::BackWark(int power){
    power =map(power,0,100,0,255);
    PikMotorL298N::RunMotor(true,false);
    PikMotorL298N::RunMotor(false,false);
    #if defined(ESP32)
        ledcWrite(14, power);
        ledcWrite(15, power);
    #else
        analogWrite(pinEnA,power);
        analogWrite(pinEnB,power);
    #endif 
}
void PikMotorL298N::TurnLeft(int power){
    power =map(power,0,100,0,255);
    PikMotorL298N::Stop();
    PikMotorL298N::RunMotor(false,true);
    #if defined(ESP32)
        ledcWrite(14, power);
    #else
        analogWrite(pinEnB,power);
    #endif 
}
void PikMotorL298N::TurnRight(int power){
    power =map(power,0,100,0,255);
    PikMotorL298N::Stop();
    PikMotorL298N::RunMotor(true,true);
    #if defined(ESP32)
        ledcWrite(15, power);
    #else
        analogWrite(pinEnA,power);
    #endif 
}
void PikMotorL298N::RunMotor(bool right,bool sens){
    int pin1 = pinIn1;
    int pin2 = pinIn2;
    if(!right){
        pin1 = pinIn3;
        pin2 = pinIn4;
    }
    if(sens){
        digitalWrite(pin2,LOW);
        digitalWrite(pin1,HIGH);
    }
    else{
        digitalWrite(pin1,LOW);
        digitalWrite(pin2,HIGH); 
    }
}
void PikMotorL298N::Stop(){
    int pins[6] ={pinIn1,pinIn2,pinIn3,pinIn4,pinEnA,pinEnB};
    for(int i = 0; i<6; i++) digitalWrite(pins[i],LOW);
    #if defined(ESP32)
        ledcWrite(14, 0);
        ledcWrite(15, 0);
    #endif 
}
int pinIn1, pinIn2, pinIn3,pinIn4,pinEnA,pinEnB;