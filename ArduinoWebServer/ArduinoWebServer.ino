#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "";
const char* password = "";

ESP8266WebServer server(8080);

const String postForms = "<!DOCTYPE html>\
<head>\
    <title>test</title>\
    <style>\
        h1 {\
            text-align: center;\
        }\
    </style>\
</head>\
<body>\
    <h1>Hello World!</h1>\
</body>\
</html>";

void handleRoot() {
  server.send(200, "text/html", postForms);
}

void setup() {
  Serial.begin(115200);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
