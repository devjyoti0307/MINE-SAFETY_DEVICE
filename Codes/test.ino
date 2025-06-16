#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "DHT.h"
#include <Wire.h>

#define DHTPIN D4         // Pin connected to DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Redmi";
const char* password = "12345678";

WiFiClient client;

// ThingSpeak Info
unsigned long channelID = 2964486;       
const char* writeAPIKey = "A3UJQNXP4IV531FS";        // Write API Key

// Pin for MQ135
int mq135Pin = A0;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
  dht.begin();
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  ThingSpeak.begin(client);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius
  int airQuality = analogRead(mq135Pin);    

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println("Temperature: " + String(temperature) + " °C");
  Serial.println("Humidity: " + String(humidity) + " %");
  Serial.println("Air Quality (MQ135): " + String(airQuality));

  // Write to ThingSpeak fields
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, airQuality);

  int x = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  delay(15000); // ThingSpeak update interval is 15 sec
}
