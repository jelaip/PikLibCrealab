#include <Arduino.h>
#include <PikUltraSonicLib.h>

PikUltraSonic sonic(5,18);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(sonic.GetDistanceCm());
  delay(100);
}