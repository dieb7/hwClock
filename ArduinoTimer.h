/*
 * ArduinoTimer.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef ARDUINOTIMER_H_
#define ARDUINOTIMER_H_

#include <ITimer.h>

class ArduinoTimer: public ranetos::ITimer {
public:
  ArduinoTimer() {}
  virtual ~ArduinoTimer() {}

  unsigned long currentMillis() {
    return millis();
  }
};

#endif /* ARDUINOTIMER_H_ */

