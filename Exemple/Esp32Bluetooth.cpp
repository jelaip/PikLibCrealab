#include <Arduino.h>
#include <PikBtLib.h>

PikBt Bt = PikBt();
void setup() {
  Serial.begin(9600);
  Bt.Init("name");
}

void loop() {
  if(Bt.Available()){
    if(Bt.ReadCommand()=="azert")
    Serial.println("ok");
  }
  delay(100);
}