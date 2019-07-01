#include "config.h"
#include "sprites.c"

// TODO does not work yet
// #include "font.h"

// https://github.com/plapointe6/EspMQTTClient
#include "EspMQTTClient.h"
#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>

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
    Serial.print(" Logo: ");
    Serial.print(logo_index);
    Serial.print(" Text: ");
    Serial.println(text);

    matrix->fillScreen(0);
    matrix->setCursor(9, 0);
    matrix->print(text);
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
  // TODO does not work yet
  // matrix->setFont(&Dialog_plain_5);
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
