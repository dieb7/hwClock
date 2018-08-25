/*
 * LedBinaryClockOutput.cpp
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#include "ledBinaryClockOutput.h"
#include "Arduino.h"

void LedBinaryClockOutput::displayValue(unsigned char value) {
  for (int i = 128; i > 0; i = i >> 1) {
    Serial.print(int((value & i) > 0));
  }
}

void LedBinaryClockOutput::show(unsigned char hour, unsigned char minute, unsigned char second) {
  for (int i = 0; i < 5; i++) {
    unsigned char mask = 1 << i;
    hourGpios[i]->setOn(bool(hour & mask) > 0);
  }

  for (int i = 0; i < 6; i++) {
    unsigned char mask = 1 << i;
    minuteGpios[i]->setOn(bool(minute & mask) > 0);
  }
}

