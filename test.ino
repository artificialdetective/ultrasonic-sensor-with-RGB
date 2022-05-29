// Example program:
#include "RGBLed.h"

// Set the pin nr wired to the ultrasonic sensor's pin marked "RGB" or "RGB_IN":
const int RGBpin = 2;   

// The ultrasonic sensor has 6 built-in leds in total: 3 in each cylinder.
RGBLed ultrasonicRGB(RGBpin, 6);


void setup() {
// Set the 3 leds in the first cylinder to one colour, 
// passing values from 0 to 255 for red, green, and blue.
for(int ledNr = 1; ledNr <= 3; ledNr++) {
  ultrasonicRGB.setColor(ledNr, 200, 255, 0);   //yellow
}

// Set the leds in the other cylinder individually:
ultrasonicRGB.setColor(4, 255, 0, 0);   //red
ultrasonicRGB.setColor(5, 0,255, 0);   //green

// Alternatively you can pass a hex colour value:
ultrasonicRGB.setColor(6, 0x0000FF);

// Apply the changes:
ultrasonicRGB.show();

delay(3000);
}


// Now we'll rotate colours across the leds in the main loop.
// Set up some hex colours:
const long RED    = 0xFF0000;
const long ORANGE = 0xFF8800;
const long YELLOW = 0xFFFF00;
const long GREEN  = 0x00FF00;
const long BLUE   = 0x0000FF;
const long PURPLE = 0xFF00FF;

// Put the colours in an array:
const long RAINBOW[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
int index = 0;


void loop() {
// Shift the rainbow array's index across [0] to [5]:
index++;
if(index == 6) {index = 0;}

// Set the colours for all leds:
for(int ledNr = 1; ledNr <= 6; ledNr++) {
  int colourNr = (index + ledNr % 2) % 6;
  ultrasonicRGB.setColor(ledNr, RAINBOW[colourNr]);
}
ultrasonicRGB.show();

// Change the colours with a certain interval.
// The smaller the delay, the faster the animation.
delay(150);
}
