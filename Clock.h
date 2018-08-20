/*
 * Clock.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <ITask.h>
#include <Timer.h>
#include "ISystemClock.h"
#include "TimeCounter.h"
#include "ClockOutput.h"

class Clock: public ranetos::ITask {
  ranetos::Timer & timer;
  ClockOutput clockOutput;
  TimeCounter hour;
  TimeCounter minute;
  TimeCounter second;
public:
  Clock(ranetos::Timer & timer, ClockOutput & clockOuput): timer(timer), clockOutput(clockOutput) {
    hour.setLimit(23);
    minute.setLimit(59);
    second.setLimit(59);
    timer.setTimeOut(1000);
    timer.start();
  }
  virtual ~Clock() {}

  virtual void work();
};

#endif /* CLOCK_H_ */

