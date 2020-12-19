#include <WebServer.h>

WebServer server(80); // listens to port 80

// setup API resources
void setup_routing() {  	 	 
  server.on("/wuermli", wuermli); // calls the wuermli function if you access the page 192.168.1.22/wuermli
  server.on("/fuerli", fuerli);
 
  // start server	 	 
  server.begin();
}