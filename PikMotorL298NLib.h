#ifndef PikMotorL298NLib.h
#define PikMotorL298NLib.h
#include <Arduino.h>

class PikMotorL298N
{
    public:
        PikMotorL298N(int _pinIn1,int _pinIn2,int _pinIn3,int _pinIn4,int _pinEnA,int _pinEnB);
        void Forward(int power);
        void BackWark(int power);
        void TurnLeft(int power);
        void TurnRight(int power);
        void TurnControl(int powerR, int powerL);
        void Stop();
        int pinIn1, pinIn2, pinIn3,pinIn4,pinEnA,pinEnB;
    private:
        void RunMotor(bool right,bool sens);
};

#endif