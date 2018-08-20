/*
 * TimeCounter.cpp
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#include "TimeCounter.h"

bool TimeCounter::increaseCount() {
  if (++timeCount > limit) {
    timeCount = 0;
    return true;
  }
  return false;
}

