/*
 * ClockOutput.h
 *
 *  Created on: Aug 19, 2018
 *      Author: diebm
 */

#ifndef CLOCKOUTPUT_H_
#define CLOCKOUTPUT_H_

class ClockOutput {
public:
  ClockOutput() {}
  virtual ~ClockOutput() {}

  void show(unsigned char hour, unsigned char minute, unsigned char second);
};

#endif /* CLOCKOUTPUT_H_ */

