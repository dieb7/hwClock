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
    if (++second > 59) {
      second = 0;
      if (++minute > 59) {
        minute = 0;
        if (++hour > 23) {
          hour = 0;
        }
      }
    }
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
  }
}

