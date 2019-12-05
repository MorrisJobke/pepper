# Pepper - A DIY La Metric clone

## Requirements

* install following dependencies via the Arduino IDE:
  * PubSubClient (https://github.com/knolleary/pubsubclient)
  * EspMQTTClient (https://github.com/plapointe6/EspMQTTClient)
* copy `config.h.dist` to `config.h` and adjust the config options

## Known limitations

* MQTT messages have a limit of 128 bytes - https://github.com/knolleary/pubsubclient/#limitations
* The font [`TomThumb`](https://robey.lag.net/2010/01/23/tiny-monospace-font.html) is quite limited in the default setting, thus it needs to be adjusted in the library folder. Open the file `Adafruit_GFX_Library/Fonts/TomThumb.h` and change `TOMTHUMB_USE_EXTENDED` to `1` and the `0x7F` in the last line of this file to `0xFF` or higher. For more details check out the [github thread](https://github.com/adafruit/Adafruit-GFX-Library/issues/144#issuecomment-429696689).

## Sprites

Sprites are generated via [Piskel](https://www.piskelapp.com) and then exported as C file.

## API

### Adjusting the text

Sending a payload to the `MQTT_SUBSCRIBE_TOPIC` topic will update the text. The payload consists of two parts. The first is the index of the sprite and the second one is the text to display. Both are separated by a space.

The example below will use the logo at index `0` with the text `Sunny`.

```
0 Sunny
```

### Adjusting the brightness

Sending a payload with an integer to the `MQTT_SUBSCRIBE_TOPIC_BRIGHTNESS` topic will update the brightness.

## Related projects

* [IoT Clock Display](https://imgur.com/gallery/VMxkOoG)
* [AWTRIX 2.0](https://blueforcer.de/awtrix-2-0/)
* [NRMetric](https://github.com/nygma2004/nrmetric)