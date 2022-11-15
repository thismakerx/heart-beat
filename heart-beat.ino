/*********************************************
  Heart Beat Example
  This Maker
  2-Sep-2022
 
  Adds a real time heartbeat pattern to an
  LED to show that the code on the device is
  still being run ie not stuck in an endless
  loop, or frozen.
**********************************************/

#define HBLED LED_BUILTIN

#include "functions.h"

void setup() 
{
  pinMode(HBLED, OUTPUT);
}

void loop() 
{
  heartBeat(HBLED);
}



