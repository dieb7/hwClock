/*
 * LedBinaryClockOutput.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef LEDBINARYCLOCKOUTPUT_H_
#define LEDBINARYCLOCKOUTPUT_H_

#include "IClockOutput.h"
#include "IGpio.h"

class LedBinaryClockOutput: public IClockOutput {
  void displayValue(unsigned char value);

  ranetos::IGpio * hourGpios[5];
  ranetos::IGpio * minuteGpios[6];
  
public:
  LedBinaryClockOutput() {}
  virtual ~LedBinaryClockOutput() {}
  
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

#endif /* LEDBINARYCLOCKOUTPUT_H_ */

