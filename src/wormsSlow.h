#include <Arduino.h>  //Arduino Libary
#include <FastLED.h>  //Fasled Libary
#include "OTA.h"      // Over the Air configuration
#include <WebServer.h> 

void wormsSlow() {
    uint16_t sinBeat   = beatsin16(1, 0, NUM_LEDS - 1, 0, 0);
    uint16_t sinBeat2  = beatsin16(1, 0, NUM_LEDS - 1, 0, 21845);
    uint16_t sinBeat3  = beatsin16(1, 0, NUM_LEDS - 1, 0, 43690);
    uint16_t sinBeat4  = beatsin16(1, 0, NUM_LEDS - 1, 0, 10000);
    uint16_t sinBeat5  = beatsin16(1, 0, NUM_LEDS - 1, 0, 30845);
    uint16_t sinBeat6  = beatsin16(1, 0, NUM_LEDS - 1, 0, 55690); //betsin16 worms slow
    
    leds[sinBeat]   = CHSV(hue,  255, 255);
    leds[sinBeat2]  = CHSV(hue2, 255, 255);
    leds[sinBeat3]  = CHSV(hue3, 255, 255);
    leds[sinBeat4]  = CHSV(hue4, 255, 255);
    leds[sinBeat5]  = CHSV(hue5, 255, 255);
    leds[sinBeat6]  = CHSV(hue6, 255, 255); // defines the colour in each betsin16 changing in worms slow

    EVERY_N_MILLISECONDS(30){
    hue++;
    } 
    
    EVERY_N_MILLISECONDS(19){
    hue2++;
    }

    EVERY_N_MILLISECONDS(1){
    hue3++;
    }

    EVERY_N_MILLISECONDS(40){
    hue4++;
    }
    
    EVERY_N_MILLISECONDS(50){
    hue5++;
    }
    
    EVERY_N_MILLISECONDS(60){
    hue6++;
    }                           //increases hue ever n milliseconds in slow
    
    EVERY_N_MILLISECONDS(1){
    for(int i = 0; i < 4; i++) {
        blur1d(leds, NUM_LEDS, 100);
    }
    }                           // blurs the LEDS out in the beatsin16 function in slow
    
    fadeToBlackBy(leds, NUM_LEDS,2);
}