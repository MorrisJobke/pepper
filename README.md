# Pepper - A DIY La Metric clone

## Requirements

* install following dependencies via the Arduino IDE:
  * PubSubClient (https://github.com/knolleary/pubsubclient)
  * EspMQTTClient (https://github.com/plapointe6/EspMQTTClient)
* copy `config.h.dist` to `config.h` and adjust the config options

## Known limitations

* MQTT messages have a limit of 128 bytes - https://github.com/knolleary/pubsubclient/#limitations
