#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include "credentials.h"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -7 * 60 * 60;   //Replace with your GMT offset (seconds)
const int   daylightOffset_sec = 3600; //Replace with your daylight offset (seconds)

void setup() {
  Serial.begin(115200);

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println("CONNECTED to WIFI");

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}


void loop() {
  while(true){
    printLocalTime();
    delay(5000);
  }
}