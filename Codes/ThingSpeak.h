#include <ThingSpeak.h>
WiFiClient client;

unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_API_KEY";

void updateThingSpeak(float temp, float humid, int airQuality) {
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humid);
  ThingSpeak.setField(3, airQuality);
  
  int x = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (x == 200) {
    Serial.println("ThingSpeak update successful.");
  } else {
    Serial.println("ThingSpeak update failed. HTTP error code: " + String(x));
  }
}