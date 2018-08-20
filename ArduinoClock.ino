#include "ArduinoTimer.h"
#include "Clock.h"

ArduinoTimer timer;
Clock myClock(timer);

void setup() {
  Serial.begin(115200);
}

void loop() {
  myClock.work();
}
