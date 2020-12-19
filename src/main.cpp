#include <Arduino.h>  //Arduino Libary
#include <FastLED.h>  //Fasled Libary
#include "OTA.h"      // Over the Air configuration
#include <WebServer.h>  // Libary for webserver
#include "wormsFastAndSlow.h"
  
//#define NUM_LEDS  300 //Number of LED's in the Strip
//#define LED_PIN   2   //Pin on The ESP 32

WebServer server(80); // listens to port 80

bool isFast = 0;  //define variable "isFast" to false



// defining HTML & CSS contents which are displayed in browser
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Hello cruel world</h1>\
<a href='/slow'><button>slow down</button></a>\
<a href='/fast'><button>hurry up</button></a>\
</body>\
</html>";

void fast() {
    Serial.println("hello cruel fast world"); 
    isFast = 1; //set variable in line 11 to true
}

void slow() {
    Serial.println("hello cruel slow world");
    isFast = 0; //set variable "isFast" (defined above) to false
}

void handleRoot() {
    server.send(200, "text/html", HTML);
}

void setup_routing() {      
  server.on("/fast", fast); // calls the wuermli function if you access the page 192.168.1.22/fast
  server.on("/slow", slow); // calls the wuermli function if you access the page 192.168.1.22/slow
  server.on("/", handleRoot);
  // start server    
  server.begin(); 
}


void setup() {        //Setup to flash the Chip
  
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS); //Type of LED, What pin on the Board, Order of the RGB
  FastLED.setBrightness(255); //Brightness level of the LED's (0-255)

  Serial.begin(57600); //sets the data  Rate on Serial  0=No Data
 
  ArduinoOTA.setHostname("leds"); //Hostname to show when looking for OTA 
  setupOTA("leds", mySSID, myPASSWORD); //Set up OTA (Hostname,mySSID and myPASSWORD defined in the credentials.h file)
  setup_routing(); //calls function setup_routing above
}


void loop() { //Loop to Flash
  ArduinoOTA.handle(); //OTA function needs to get called once in a while

  // put main code here

  server.handleClient(); // handelt de kliänt

  if (isFast == 0) { // if variable "isFast" set to 0 via port 80 on 192.168.1.22/slow this code runs until elif below
    
    wormsSlow();// calls the function wormsSlow in the file wormsSlow.h
  
  } else if (isFast == 1) {     //if variable isFast is set to 1 this code runs instead of slow above
    
    wormsFast(); // calls the function wormsFast in the file wormsFast.h
  
  }

  FastLED.show(); //runs led program repeated because in "Loop"
}