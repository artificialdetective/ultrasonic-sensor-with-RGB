# How to set the RGB leds of the RUS-04 ultrasonic distance sensor for Arduino

The RUS-04 ultrasonic distance sensor has six RGB leds built into its speakers, but no clear documentation on how to use them, so here is how.
For measuring distance, the RUS-04 sensor works the same as the common HC-SR04 sensor for which there are plenty of tutorials to find, so we won't cover that here.

The RUS-04's manufacturer is Emakefun (www.emakefun.com), who only offers minimal documentation in Chinese:  
https://test-doc-zh-cn.readthedocs.io/projects/emakefun/zh_CN/latest/open_source_hardware/rgb/

They use the RgbUltrasonic code library, which you can find somewhere in here if you prefer:  
https://github.com/emakefun/hummer-bot/tree/Hummer-bot4.0/Lesson/Module_Test/RGBUltrasonicModule_Test

However, all we need from there to control the RGB leds is the RGBLed library, which consists of two files: RGBLed.cpp and RGBLed.h
The original RGBLed.cpp file contains mistakes in the order of the colour parameters in several functions, which I've fixed in this repository.
Install these two files as a library or simply place them in the same folder as your Arduino program's .ino file in order to use the RGB functions.

To try it out, upload the "test.ino" program to your Arduino. Adjust its code to your needs.  
Basically, use the .setColour() function to set a led's colour, then the .show() function to actually apply the change.  
The sensor module remembers the last-set colours even if you reset your Arduino.


# Minimal Arduino program example
#include "RGBLed.h"  

// Set the pin nr connected to the ultrasonic sensor's pin marked "RGB_IN":  
const int ultrasonicRGBPin = 2;  

// The ultrasonic sensor has 6 leds in total: 3 in each cylinder.  
RGBLed ultrasonicRGB(ultrasonicRGBPin, 6);  

void setup() {  
  // Set all 6 leds to a colour,  
  // specifying the number of the led (1-6), followed by values between 0 and 255 for red, green, and blue.  
  for(int ledNr = 1; ledNr <= 6; ledNr++) {ultrasonicRGB.setColor(ledNr, 0, 255, 0);}  

  // Apply the changes:  
  ultrasonicRGB.show();  
}  

void loop() {  
  
}  
