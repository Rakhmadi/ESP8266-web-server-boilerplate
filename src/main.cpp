#include <Arduino.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

const char* ssid = "HexaTerrax"; //Enter SSID
const char* password = "12345678"; //Enter Password

ESP8266WebServer server(80);

void x(){
  server.send(200,"text/plain","Hello World");
}
void Routers(){
  server.on("/",HTTP_GET,x);
}
void setup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
     delay(500);
     Serial.print("*");
  }
  Serial.begin(9600);
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
  Routers();
  server.begin();

}

void loop() {
  server.handleClient();
}