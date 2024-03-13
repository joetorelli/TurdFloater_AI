/*
  testing the ticktwo lib with feather esp32

*/

#include <Arduino.h>
#include "TickTwo.h"

// function ptrototypes for timer calls
void printMessage();
void printCounter();
void printCountdown();
void blink();
void printCountUS();

bool ledState;
int counterUS;

// associate timer to function
// TickTwo TimerName(function call, interval, # of repeats, resolution);
TickTwo timer1Message(printMessage, 0, 1);                  // run once now
TickTwo timer2Counter(printCounter, 1000, 0, MILLIS);       // run every 1000ms forever
TickTwo timer3Countdown(printCountdown, 1000, 5);           // run every 1000ms for 5x
TickTwo timer4blink(blink, 500);                            // run every 500ms forever
TickTwo timer5CountUS(printCountUS, 100, 0, MICROS_MICROS); // run every 100us forever

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(2000); // do not use delay after timer.start();

  // enable timers
  timer1Message.start();
  timer2Counter.start();
  timer3Countdown.start();
  timer4blink.start();
  timer5CountUS.start();
}

void loop()
{

  // must run every loop to check timer status
  timer1Message.update();
  timer2Counter.update();
  timer3Countdown.update();
  timer4blink.update();
  timer5CountUS.update();

  if (timer4blink.counter() == 20) // ck count and change interval
    timer4blink.interval(200);
  if (timer4blink.counter() == 80)
    timer4blink.interval(1000);
}

////////////////////// function calls
void printCounter()
{
  Serial.print("Counter ");
  Serial.println(timer2Counter.counter());
  if ((timer2Counter.counter() % 10) == 0) // call another timer every 10th time
  {
    timer1Message.resume();
  }
}

void printCountdown()
{
  Serial.print("Countdowm ");
  Serial.println(5 - timer3Countdown.counter());
}

void printMessage()
{
  Serial.println("Hello!");
}

void blink()
{
  digitalWrite(LED_BUILTIN, ledState);
  ledState = !ledState;
}

void printCountUS()
{
  counterUS++;
  if (counterUS == 10000)
  {
    Serial.println("10000 * 100us");
    counterUS = 0;
  }
}
