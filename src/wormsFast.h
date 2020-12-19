#include <Arduino.h>  //Arduino Libary
#include <FastLED.h>  //Fasled Libary
#include "OTA.h"      // Over the Air configuration
#include <WebServer.h> 

void wormsFast() {
    uint16_t sinBeat   = beatsin16(3, 0, NUM_LEDS - 1, 0, 0);
    uint16_t sinBeat2  = beatsin16(3, 0, NUM_LEDS - 1, 0, 21845);
    uint16_t sinBeat3  = beatsin16(3, 0, NUM_LEDS - 1, 0, 43690);
    uint16_t sinBeat4  = beatsin16(3, 0, NUM_LEDS - 1, 0, 10000);
    uint16_t sinBeat5  = beatsin16(3, 0, NUM_LEDS - 1, 0, 30845);
    uint16_t sinBeat6  = beatsin16(3, 0, NUM_LEDS - 1, 0, 55690); //beatsin function in "fast"
    
    leds[sinBeat]   = CHSV(hue,  255, 255);
    leds[sinBeat2]  = CHSV(hue2, 255, 255);
    leds[sinBeat3]  = CHSV(hue3, 255, 255);
    leds[sinBeat4]  = CHSV(hue4, 255, 255);
    leds[sinBeat5]  = CHSV(hue5, 255, 255);

    leds[sinBeat6]  = CHSV(hue6, 255, 255); // Defines colours in worms "fast"
 
    EVERY_N_MILLISECONDS(3){
      hue++;
    } 
    
    EVERY_N_MILLISECONDS(6){
      hue2++;
    }

    EVERY_N_MILLISECONDS(2){
      hue3++;
    }

    EVERY_N_MILLISECONDS(8){
      hue4++;
    }
    
    EVERY_N_MILLISECONDS(10){
      hue5++;
    }
    
    EVERY_N_MILLISECONDS(12){
      hue6++;
    }                         //changes hue ever n milliseconds in "fast"
    
    EVERY_N_MILLISECONDS(1){
      for(int i = 0; i < 4; i++) {
        blur1d(leds, NUM_LEDS, 100);
      }                                   //blurs leds in "fast"
    }
    
    fadeToBlackBy(leds, NUM_LEDS,2);      //fasde to black by in "fast"
}