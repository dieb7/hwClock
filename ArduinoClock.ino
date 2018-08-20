#include "ArduinoTimer.h"

ArduinoTimer timer;
bool stateOn = true;

void turnOnLed(bool on) {
  if (on) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void setup() {
  timer.setTimeOut(1000);
  timer.start();
  pinMode(LED_BUILTIN, OUTPUT);

  stateOn = true;
  turnOnLed(stateOn);
  
}

void loop() {
  if (timer.timedOut()) {
    turnOnLed(stateOn);
    stateOn = !stateOn;
    timer.start();
  }
}
