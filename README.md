# heart-beat
Example code for adding a heart beat to an Arduino project to show in real time the code is running.

Lighting an LED through code to show a device is running could traditionally be done using digitalWrite() from the setup() method. 
While this would work, in reality it is nothing more than a power indicator. Should the code lock up, or get stuck in an endless loop
the LED would continue to glow. This could give the user an inaccurate view of the device status.

An LED being controlled in the main() loop to turn on and off would be a better solution.

Arduino kindly supplies the blink example sketch which indeed blinks an LED on and off in the main() loop. This has the issue that it 
uses the delay() method to determine how long the LED should remain on and off for. During that delay all other code is also halted
which would make timing critical applications so much harder to implement.

Instead, it would be much more feasible to test each loop whether a certain time period had passed and only toggle the state of the LED
when that condition is met. This can be done quite easily, and can produce lighting sequences with very good timing accuracy.

This project aims to not only toggle an LED with a static onDelay offDelay pattern, but expand on that to allow a sequential string of
patterns, specifically that of a heart beat. It could of course be expanded to send out a string of Morse code, or any other patterned
sequence that the programmer wishes.

A state machine will be implemented to control the sequence, and the specific code broken out into an external file that can be simply
added to any existing project while not cluttering the main code block.