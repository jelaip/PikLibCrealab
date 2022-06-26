#include <Arduino.h>
#include <PikBtLib.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

PikBt::PikBt(){
  BT = new BluetoothSerial();
}
void PikBt::Init(String name){
    BT->begin(name);
}

bool PikBt::Available(){
    return BT->available();
}
char PikBt::ReadChar(){
    char c = (char)BT->read();
    return c;
    
}
void PikBt::SendMsg(String msg){
    BT->println(msg);
}

String PikBt::ReadCommand(){
    String s;
    while(BT->available()){ 
        int i = BT->read();
        if(i == 13) break;
        char c = (char)i;
        s+=c;
    }
    return s;
}