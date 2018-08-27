#include "ArduinoSystemClock.h"
#include "Timer.h"
#include "ledBinaryClockOutput.h"
#include "Clock.h"
#include "ArduinoGpio.h"
#include "DebounceGpio.h"
#include "OneShotGpio.h"
#include "ClockTimeAdjuster.h"
#include "TomateTimer.h"

ArduinoSystemClock systemClock;
ranetos::Timer timer(systemClock);
LedBinaryClockOutput clockOutput;
Clock myClock(timer);
ClockTimeAdjuster timeAdjuster;

ArduinoGpio hourGpio0(A0, true);
ArduinoGpio hourGpio1(A1, true);
ArduinoGpio hourGpio2(A2, true);
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

ArduinoGpio tomateStartGpio(2, false);
ranetos::Timer debounceDelayTomateStart(systemClock);
ranetos::DebounceGpio tomateStartDebounce(tomateStartGpio, debounceDelayTomateStart, 80);
ranetos::OneShotGpio tomateStart(tomateStartDebounce);

ranetos::Timer tTimer(systemClock);
TomateTimer tomateTimer(tTimer, tomateStart);
ArduinoGpio tomateGpioBreak(A3, true);
ArduinoGpio tomateGpioActive(13, true);

void setup() {  
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

  myClock.setOutput(&clockOutput);

  timeAdjuster.setIncrementHourButton(&hourIncrement);
  timeAdjuster.setIncrementMinuteButton(&minuteIncrement);
  timeAdjuster.setClock(&myClock);
}

void loop() {
  myClock.work();
  timeAdjuster.work();
  tomateTimer.work();

  switch (tomateTimer.currentState()) {
  case TomateTimer::State::IDLE_STATE:
    tomateGpioBreak.setOn(false);
    tomateGpioActive.setOn(false);
    break;
  case TomateTimer::State::ACTIVE_STATE:
    tomateGpioBreak.setOn(false);
    tomateGpioActive.setOn(true);
    break;
  case TomateTimer::State::BREAK_STATE:
    tomateGpioBreak.setOn(true);
    tomateGpioActive.setOn(false);
    break;
  default:
    break;
  }
}
