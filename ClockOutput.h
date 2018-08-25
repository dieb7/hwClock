/*
 * ClockOutput.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef CLOCKOUTPUT_H_
#define CLOCKOUTPUT_H_

#include "IGpio.h"

class ClockOutput {
  void displayValue(unsigned char value);

  ranetos::IGpio * hourGpios[5];
  ranetos::IGpio * minuteGpios[6];
  
public:
  ClockOutput() {}
  virtual ~ClockOutput() {}
  
  void setHourGpio(ranetos::IGpio *hourGpio, unsigned char index) {
    if (index < 5) {
      this->hourGpios[index] = hourGpio;
    }
  }


  void setMinuteGpio(ranetos::IGpio *minuteGpio, unsigned char index) {
    if (index < 6) {
      this->minuteGpios[index] = minuteGpio;
    }
  }


  void show(unsigned char hour, unsigned char minute, unsigned char second);
};

#endif /* CLOCKOUTPUT_H_ */

