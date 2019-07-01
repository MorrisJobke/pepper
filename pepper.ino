#include "config.h"
#include "sprites.c"

// https://github.com/plapointe6/EspMQTTClient
#include "EspMQTTClient.h"
#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include <Fonts/TomThumb.h>

#define PIN 4
#define TYPE NEOPIXEL // seems to be the same as WS2812B + RGB
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 8
#define NUMMATRIX (MATRIX_WIDTH*MATRIX_HEIGHT)

EspMQTTClient client(
  SSID_NAME,
  SSID_PASSWORD,
  MQTT_SERVER,
  MQTT_CLIENT_ID
);

CRGB matrixleds[NUMMATRIX];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(
  matrixleds,
  MATRIX_WIDTH,
  MATRIX_HEIGHT,
  1,
  1,
  NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG
);

void onConnectionEstablished() {
  client.subscribe(MQTT_SUBSCRIBE_TOPIC, [] (const String &payload)  {
    int index = payload.indexOf(' ');
    int logo_index = atoi(payload.substring(0, index).c_str());
    const String text = payload.substring(index + 1);

    Serial.print("Payload: ");
    Serial.println(payload);
    Serial.print("Logo: ");
    Serial.print(logo_index);
    Serial.print(" Text: ");
    Serial.println(text);

    matrix->fillScreen(0);
    matrix->setCursor(9, 6);
    matrix->print(utf8ascii(text));
    drawLogo(logo_index);

    matrix->show();
  });
  client.subscribe(MQTT_SUBSCRIBE_TOPIC_BRIGHTNESS, [] (const String &payload)  {
    Serial.print("Brightness: ");
    Serial.println(payload);

    matrix->setBrightness(atoi(payload.c_str()));
    matrix->show();
  });
}

void setup() {
  Serial.begin(115200);
  Serial.println("");

  FastLED.addLeds<TYPE,PIN>(matrixleds, NUMMATRIX).setCorrection(TypicalLEDStrip);
  matrix->begin();
  matrix->setBrightness(40);
  matrix->setTextWrap(false);
  matrix->setFont(&TomThumb);
  matrix->setTextColor(
    matrix->Color(255, 255, 255)
  );
  matrix->fillScreen(0);
  matrix->show();
}

void loop() {
  client.loop();
}

void drawLogo(unsigned int logo_index) {
  if (logo_index >= SPRITES_FRAME_COUNT) {
    Serial.println("drawLogo: logo_index out of boundaries - fallback to first logo");
    logo_index = 0;
  }
  const unsigned int* logo = sprites_data[logo_index];

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      int index = i * 8 + j;

      // arduino is little endian thus the bit shifts work
      uint8_t red          = logo[index];
      uint8_t green        = logo[index] >>  8;
      uint8_t blue         = logo[index] >> 16;
      uint8_t transparency = logo[index] >> 24;

      matrix->drawPixel(
        j,
        i,
        matrix->Color(red, green, blue));
    }
  }

  matrix->show();
}


// utf8ascii convertion from https://github.com/awtrix/AWTRIX2.0-Controller/blob/098a8bd10156b1085122944500b31f2e7a0afe27/src/AWTRIXController.cpp#L48-L86
static byte c1;  // Last character buffer
byte utf8ascii(byte ascii) {
  if ( ascii < 128 ) // Standard ASCII-set 0..0x7F handling
  { c1 = 0;
    return ( ascii );
  }
  // get previous input
  byte last = c1;   // get last char
  c1 = ascii;       // remember actual character
  switch (last)     // conversion depending on first UTF8-character
  { case 0xC2: return  (ascii) - 34;  break;
    case 0xC3: return  (ascii | 0xC0) - 34;  break;
    case 0x82: if (ascii == 0xAC) return (0xEA);
  }
  return  (0);
}

String utf8ascii(String s) {
  String r = "";
  char c;
  for (int i = 0; i < s.length(); i++)
  {
    c = utf8ascii(s.charAt(i));
    if (c != 0) r += c;
  }
  return r;
}

void utf8ascii(char* s) {
  int k = 0;
  char c;
  for (int i = 0; i < strlen(s); i++)
  {
    c = utf8ascii(s[i]);
    if (c != 0)
      s[k++] = c;
  }
  s[k] = 0;
}
