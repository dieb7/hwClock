#include "ArduinoSystemClock.h"
#include "Timer.h"
#include "ClockOutput.h"
#include "Clock.h"
#include "ArduinoGpio.h"


ArduinoSystemClock systemClock;
ranetos::Timer timer(systemClock);
ClockOutput clockOutput;
Clock myClock(timer);


ArduinoGpio hourGpio0(2, true);
ArduinoGpio hourGpio1(3, true);
ArduinoGpio hourGpio2(4, true);

ArduinoGpio minuteGpio0(5, true);
ArduinoGpio minuteGpio1(6, true);
ArduinoGpio minuteGpio2(7, true);
ArduinoGpio minuteGpio3(8, true);
ArduinoGpio minuteGpio4(9, true);
ArduinoGpio minuteGpio5(10, true);

void setup() {
  clockOutput.setHourGpio(&hourGpio0, 2);
  clockOutput.setHourGpio(&hourGpio1, 1);
  clockOutput.setHourGpio(&hourGpio2, 0);

  clockOutput.setMinuteGpio(&minuteGpio0, 5);
  clockOutput.setMinuteGpio(&minuteGpio1, 4);
  clockOutput.setMinuteGpio(&minuteGpio2, 3);
  clockOutput.setMinuteGpio(&minuteGpio3, 2);
  clockOutput.setMinuteGpio(&minuteGpio4, 1);
  clockOutput.setMinuteGpio(&minuteGpio5, 0);
}

void loop() {
  myClock.work();
  
  unsigned char hour = myClock.currentHour();
  unsigned char minute = myClock.currentMinute();
  unsigned char second = myClock.currentSecond();

  clockOutput.show(hour, minute, second);
}
