/*
 * ClockOutput.cpp
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#include "ClockOutput.h"
#include "Arduino.h"

void ClockOutput::show(unsigned char hour, unsigned char minute, unsigned char second) {
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}

