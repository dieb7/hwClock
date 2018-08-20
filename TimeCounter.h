/*
 * TimeCounter.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef TIMECOUNTER_H_
#define TIMECOUNTER_H_

class TimeCounter {
  unsigned char timeCount;
  unsigned char limit;
public:
  TimeCounter() {
    timeCount = 0;
    limit = 0;
  }
  virtual ~TimeCounter() {}

  unsigned char getLimit() const {
    return limit;
  }

  void setLimit(unsigned char limit) {
    this->limit = limit;
  }

  unsigned char getTimeCount() const {
    return timeCount;
  }

  void setTimeCount(unsigned char timeCount) {
    this->timeCount = timeCount;
  }

  bool increaseCount();
};

#endif /* TIMECOUNTER_H_ */

