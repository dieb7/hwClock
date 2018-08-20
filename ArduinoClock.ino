#include "ArduinoSystemClock.h"
#include "Timer.h"
#include "Clock.h"


ArduinoSystemClock systemClock;
ranetos::Timer timer(systemClock);
Clock myClock(timer);

void setup() {
  Serial.begin(115200);
}

void loop() {
  myClock.work();
}
