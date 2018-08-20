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

class Clock: public ranetos::ITask {
  ranetos::ITimer & timer;
  unsigned char hour;
  unsigned char minute;
  unsigned char second;
public:
  Clock(ranetos::ITimer & timer): timer(timer) {
    hour = 0;  
    minute = 0;
    second = 0;
    timer.setTimeOut(1000);
    timer.start();
  }
  virtual ~Clock() {}

  virtual void work();
};

#endif /* CLOCK_H_ */

