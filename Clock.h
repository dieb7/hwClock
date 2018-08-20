/*
 * Clock.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <ITask.h>
#include <ITimer.h>
#include "TimeCounter.h"

class Clock: public ranetos::ITask {
  ranetos::ITimer & timer;
  TimeCounter hour;
  TimeCounter minute;
  TimeCounter second;
public:
  Clock(ranetos::ITimer & timer): timer(timer) {
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

