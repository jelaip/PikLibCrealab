#include <Arduino.h>
#include <PikButtonLib.h>

PikButton button(5);

void setup(){
  Serial.begin(9600);
}
void loop() {
  Serial.println(button.Value());
  delay(100);
}