#ifndef PikLedLib.h
#define PikLedLib.h
#include <Arduino.h>
#include "BluetoothSerial.h"
class PikBt
{
    public:
        PikBt();
        BluetoothSerial* BT;
        void Init(String name);
        bool Available();
        char ReadChar();
        String ReadCommand();
        void SendMsg(String msg);
};

#endif