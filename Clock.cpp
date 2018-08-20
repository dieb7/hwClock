/*
 * Clock.cpp
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#include "Clock.h"
#include "Arduino.h"

void Clock::work() {
  if (timer.timedOut()) {
    timer.start();
    if (second.increaseCount()) {
      if (minute.increaseCount()) {
        hour.increaseCount();
      }
    }
    Serial.print(hour.getTimeCount());
    Serial.print(":");
    Serial.print(minute.getTimeCount());
    Serial.print(":");
    Serial.println(second.getTimeCount());
  }
}

