/*
 1. We can use an LED to show that a circuit is receiving power. That doesn't show that the circuit is doing
    anything else though.
 2. We can use an LED that is switched on by the uC to show that the code has run that instruction, but if
    the code were to lock up for some reason, the LED would be a false indicator as well.
 3. The blink example turns an LED on and off. That would effectively show that the code is running those 
    instructions but there is a compromise. The delay function that is used to slow the on and off times of 
    the LED will also delay any other code that is running as well. For a timing sensitive circuit this could
    cause huge issues.
 4. Instead we want to turn the LED on and off at set times without holding up the other code. We can do this 
    using Arduinos built in timer to keep track of when we want to turn on and off the LED.
 5. To tidy up the code we can employ a coding method known as a state machine.
 6. The state machine lets us add more functionality. We can use additional states to create a pattern. What
    pattern is more fitting than a heart beat?
 7. The heart beat is looking really good, but the code could use some work. Right now there's a lot of code
    to sift through when we want to make changes. We can make our code a bit tidier using abstraction. Looking
    at the state machine we can see that the code for each state is a very similar pattern to each other. We
    can make the state changes look much confusing by abstracting that code into a single function.
 8. The code has shrunk down a lot now. In fact, if we needed to add more patterns it would be considerably 
    easier. We can do better though. We'll move our two functions into an external file that we'll include
    at compile time.
 9. Finally, what we have now is what we call boiler plate code. We can use this code as a shell for all of 
    our future projects. We can clone this project as the basis for anything we want that needs a heart beat.
*/

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



