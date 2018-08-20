/*
 * ArduinoSystemClock.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef ARDUINOSYSTEMCLOCK_H_
#define ARDUINOSYSTEMCLOCK_H_

#include "ISystemClock.h"
#include "Arduino.h"

class ArduinoSystemClock: public ranetos::ISystemClock {
public:
  ArduinoSystemClock() {}
  virtual ~ArduinoSystemClock() {}

  virtual unsigned long milliseconds() {
    return millis();
  }
};

#endif /* ARDUINOSYSTEMCLOCK_H_ */

