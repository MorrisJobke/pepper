#include "config.h"

// https://github.com/plapointe6/EspMQTTClient
#include "EspMQTTClient.h"

EspMQTTClient client(
  SSID_NAME,
  SSID_PASSWORD,
  MQTT_SERVER,
  MQTT_CLIENT_ID
);

void onConnectionEstablished() {
  client.subscribe(MQTT_SUBSCRIBE_TOPIC, [] (const String &payload)  {
    Serial.println(payload);
  });

  client.publish(MQTT_SUBSCRIBE_TOPIC, "Pepper is online");
}

void setup() {
  Serial.begin(115200);
  Serial.println("");
}

void loop() {
  client.loop();
}