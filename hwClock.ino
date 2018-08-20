#include "ArduinoSystemClock.h"
#include "Timer.h"
#include "ClockOutput.h"
#include "Clock.h"


ArduinoSystemClock systemClock;
ranetos::Timer timer(systemClock);
ClockOutput clockOutput;
Clock myClock(timer, clockOutput);

void setup() {
  Serial.begin(115200);
}

void loop() {
  myClock.work();
}
