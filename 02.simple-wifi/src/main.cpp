#include <Arduino.h>
#include <WiFi.h>

#define LED 2
#define GPIO_LED 13

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // set the LED pin mode
  pinMode(GPIO_LED, GPIO_MODE_OUTPUT); 

  Serial.println("Simple Wi-Fi Example");
 
  Serial.println(String("Connect try : ") + WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while(WiFi.status() != WL_CONNECTED )
  {
    delay(500);
    Serial.println(".");
  }
  Serial.print(String("WIFI conneted\n IP : "));
  Serial.println(WiFi.localIP());
  server.begin();
}

int value = 0;

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 13 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 13 off.<br>");
            client.println();
            break;
          } else {
            // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        if (currentLine.endsWith("GET /H")) {
          digitalWrite(GPIO_LED, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(GPIO_LED, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
