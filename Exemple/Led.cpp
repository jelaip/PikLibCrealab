#include <Arduino.h>
#include <PikLedLib.h>

PikLed led1(2);

void setup(){
  
}
void loop() {
  led1.On();
  delay(100);
  led1.Off();
  delay(100);
}