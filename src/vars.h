#define NUM_LEDS  300 //Number of LED's in the Strip
#define LED_PIN   2   //Pin on The ESP 32

CRGB leds[NUM_LEDS];  //Defines the RGB Pixel 
uint8_t hue  = 0;
uint8_t hue2 = 30;
uint8_t hue3 = 255;
uint8_t hue4 = 100;
uint8_t hue5 = 150;
uint8_t hue6 = 60; //variable for Colour-Chan