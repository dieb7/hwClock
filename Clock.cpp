/*
 * Clock.cpp
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#include "Clock.h"

void Clock::work() {
  if (timer.timedOut()) {
    timer.start();
    if (second.increaseCount()) {
      if (minute.increaseCount()) {
        hour.increaseCount();
      }
    }
    clockOutput.show(hour.getTimeCount(), minute.getTimeCount(), second.getTimeCount());
  }
}

