#include "ArduinoSystemClock.h"
#include "Timer.h"
#include "ClockOutput.h"
#include "Clock.h"
#include "ArduinoGpio.h"
#include "DebounceGpio.h"
#include "OneShotGpio.h"


ArduinoSystemClock systemClock;
ranetos::Timer timer(systemClock);
ClockOutput clockOutput;
Clock myClock(timer);

ArduinoGpio hourGpio0(A0, true);
ArduinoGpio hourGpio1(A1, true);
ArduinoGpio hourGpio2(2, true);
ArduinoGpio hourGpio3(3, true);
ArduinoGpio hourGpio4(4, true);

ArduinoGpio minuteGpio0(5, true);
ArduinoGpio minuteGpio1(6, true);
ArduinoGpio minuteGpio2(7, true);
ArduinoGpio minuteGpio3(8, true);
ArduinoGpio minuteGpio4(9, true);
ArduinoGpio minuteGpio5(10, true);

ArduinoGpio hourIncrementGpio(11, false);
ranetos::Timer debounceDelayHour(systemClock);
ranetos::DebounceGpio hourIncrementDebounce(hourIncrementGpio, debounceDelayHour, 80);
ranetos::OneShotGpio hourIncrement(hourIncrementDebounce);

ArduinoGpio minuteIncrementGpio(12, false);
ranetos::Timer debounceDelayMinute(systemClock);
ranetos::DebounceGpio minuteIncrementDebounce(minuteIncrementGpio, debounceDelayMinute, 80);
ranetos::OneShotGpio minuteIncrement(minuteIncrementDebounce);

void setup() {
  hourGpio0.setOutput(true);
  hourGpio1.setOutput(true);
  
  clockOutput.setHourGpio(&hourGpio0, 4);
  clockOutput.setHourGpio(&hourGpio1, 3);
  clockOutput.setHourGpio(&hourGpio2, 2);
  clockOutput.setHourGpio(&hourGpio3, 1);
  clockOutput.setHourGpio(&hourGpio4, 0);

  clockOutput.setMinuteGpio(&minuteGpio0, 5);
  clockOutput.setMinuteGpio(&minuteGpio1, 4);
  clockOutput.setMinuteGpio(&minuteGpio2, 3);
  clockOutput.setMinuteGpio(&minuteGpio3, 2);
  clockOutput.setMinuteGpio(&minuteGpio4, 1);
  clockOutput.setMinuteGpio(&minuteGpio5, 0);
}

void loop() {
  myClock.work();

  if (hourIncrement.isOn()) {
    myClock.incrementHour();
  }

  if (minuteIncrement.isOn()) {
    myClock.incrementMinute();;
  }
  
  unsigned char hour = myClock.currentHour();
  unsigned char minute = myClock.currentMinute();
  unsigned char second = myClock.currentSecond();

  clockOutput.show(hour, minute, second);
}
