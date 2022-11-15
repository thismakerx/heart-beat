#include "functions.h"

bool runOnce = false;
unsigned long hbTime = millis();
int hbState = 4;

// You need to declare functions if you want them to be abstracted outside the order of their use:
void alterState(byte pin, int ledNewState, int hbNewState, int sequence);


void heartBeat(byte pin)
{
  // Sequence timing 60 bpm
  int hb1On   = 150; // time in ms
  int hb1Off  = 50;
  //int hb1Int  = 255;  
  int hb2On   = 100;
  int hb2Off  = 700;
  //int hb2Int  = 75;
   
  // State machine
  switch (hbState)
  {
    case 1:
      alterState(pin, HIGH, 2, hb1On);  // HIGH
      break;

    case 2:
      alterState(pin, LOW, 3, hb1Off);  // LOW
      break;

    case 3:
      alterState(pin, HIGH, 4, hb2On);  // HIGH
      break;

    case 4:
      alterState(pin, LOW, 1, hb2Off);  // LOW
      break;
  }

}

void alterState(byte pin, int ledNewState, int hbNewState, int sequence)
{
  if (!runOnce) 
  {        
    digitalWrite(pin, ledNewState);
    runOnce = true;
  }

  if (millis() - hbTime > sequence)
  {
    runOnce = false;
    hbState = hbNewState;
    hbTime = millis();
  }
}