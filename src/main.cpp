#include <Arduino.h>
#include <FastLED.h>
#include "OTA.h"
#include <WebServer.h>
  
#define NUM_LEDS  300 //Number of LED's in the Strip
#define LED_PIN   2   //Pin on The ESP 32

WebServer server(80); // listens to port 80


CRGB leds[NUM_LEDS];  //Defines the RGB Pixel 
uint8_t hue  = 0;
uint8_t hue2 = 30;
uint8_t hue3 = 255;
uint8_t hue4 = 100;
uint8_t hue5 = 150;
uint8_t hue6 = 60;

void fuerli() {
    uint16_t sinBeat   = beatsin16(1, 0, NUM_LEDS - 1, 0, 0);
    uint16_t sinBeat2  = beatsin16(1, 0, NUM_LEDS - 1, 0, 21845);
    uint16_t sinBeat3  = beatsin16(1, 0, NUM_LEDS - 1, 0, 43690);
    uint16_t sinBeat4  = beatsin16(1, 0, NUM_LEDS - 1, 0, 10000);
    uint16_t sinBeat5  = beatsin16(1, 0, NUM_LEDS - 1, 0, 30845);
    uint16_t sinBeat6  = beatsin16(1, 0, NUM_LEDS - 1, 0, 55690);
    
    leds[sinBeat]   = CHSV(hue,  255, 255);
    leds[sinBeat2]  = CHSV(hue2, 255, 255);
    leds[sinBeat3]  = CHSV(hue3, 255, 255);
    leds[sinBeat4]  = CHSV(hue4, 255, 255);
    leds[sinBeat5]  = CHSV(hue5, 255, 255);
    leds[sinBeat6]  = CHSV(hue6, 255, 255);

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
    }
    
    EVERY_N_MILLISECONDS(1){
      for(int i = 0; i < 4; i++) {
        blur1d(leds, NUM_LEDS, 100);
      }
    }
    
    fadeToBlackBy(leds, NUM_LEDS,2);
  }

void wuermli() {
    uint16_t sinBeat   = beatsin16(1, 0, NUM_LEDS - 1, 0, 0);
    uint16_t sinBeat2  = beatsin16(1, 0, NUM_LEDS - 1, 0, 21845);
    uint16_t sinBeat3  = beatsin16(1, 0, NUM_LEDS - 1, 0, 43690);
    uint16_t sinBeat4  = beatsin16(1, 0, NUM_LEDS - 1, 0, 10000);
    uint16_t sinBeat5  = beatsin16(1, 0, NUM_LEDS - 1, 0, 30845);
    uint16_t sinBeat6  = beatsin16(1, 0, NUM_LEDS - 1, 0, 55690);
    
    leds[sinBeat]   = CHSV(hue,  255, 255);
    leds[sinBeat2]  = CHSV(hue2, 255, 255);
    leds[sinBeat3]  = CHSV(hue3, 255, 255);
    leds[sinBeat4]  = CHSV(hue4, 255, 255);
    leds[sinBeat5]  = CHSV(hue5, 255, 255);
    leds[sinBeat6]  = CHSV(hue6, 255, 255);

    EVERY_N_MILLISECONDS(300){
      hue++;
    } 
    
    EVERY_N_MILLISECONDS(190){
      hue2++;
    }

    EVERY_N_MILLISECONDS(10){
      hue3++;
    }

    EVERY_N_MILLISECONDS(400){
      hue4++;
    }
    
    EVERY_N_MILLISECONDS(500){
      hue5++;
    }
    
    EVERY_N_MILLISECONDS(600){
      hue6++;
    }
    
    EVERY_N_MILLISECONDS(1){
      for(int i = 0; i < 4; i++) {
        blur1d(leds, NUM_LEDS, 100);
      }
    }
    
    fadeToBlackBy(leds, NUM_LEDS,2);
  }

Serial.print("Connected. IP: ");
Serial.println(WiFi.localIP());

void setup_routing() {  	 	 
  server.on("/wuermli", wuermli); // calls the wuermli function if you access the page 192.168.1.22/wuermli
  server.on("/fuerli", fuerli);
 
  // start server	 	 
  server.begin();
}


void setup() {        //Setup to flash the Chip
  
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS); //Type of LED, What pin on the Board, Order of the RGB
  FastLED.setBrightness(255); //Brightness level of the LED's (0-255)

  Serial.begin(57600); //sets the data  Rate on Serial (USB) 0=No Data
 
  ArduinoOTA.setHostname("LED_Band_Gitarrene"); //Hostname to show when looking for OTA 
    setupOTA("LED_Band_Gitarrene", mySSID, myPASSWORD); //Set up OTA (Hostname,mySSID and myPASSWORD defined in the credentials.h file)
  setup_routing()
}


void loop() { //Loop to Flash
  ArduinoOTA.handle(); //OTA function needs to get called once in a while

  // put main code here

  server.handleClient();

  FastLED.show();
}