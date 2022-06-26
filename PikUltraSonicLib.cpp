#include <Arduino.h>
#include <PikUltraSonicLib.h>

PikUltraSonic::PikUltraSonic(int _pinTrig, int _pinEcho){
    trigPin = _pinTrig;
    echoPin = _pinEcho;
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
}

float PikUltraSonic::GetDistanceCm(){
    long duration;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    return duration*0.034/2;
}
float PikUltraSonic::GetDistanceInch(){
    return PikUltraSonic::GetDistanceCm()*0.393701;
}

