#include <Arduino.h>
#include <PikAnalogInLib.h>

PikAnalogIn AnalogIn1(4);

void setup(){
  Serial.begin(9600);
}
void loop() {
  Serial.println(AnalogIn1.Value());
  delay(100);
}