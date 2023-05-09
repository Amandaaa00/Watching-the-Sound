#include "Freenove_WS2812_Lib_for_ESP32.h"
#define LEDS_COUNT 30 // The number of led
#define LEDS_PIN 2 // define the pin connected to the Freenove 8 led strip
#define CHANNEL 0 // RMT channel
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);
u8 m_color[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0} };
//set the color values to be used, as red, green, blue, white, and black.

int delayval = 5;

int MicVolume = 0;

int HighestVol = 3000;

void setup() {
  strip.begin();
  strip.setBrightness(5);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  MicVolume = (analogRead(32));
  Serial.println(MicVolume);

  if (MicVolume <= 1900){
    for (int i = 0; i < LEDS_COUNT+1; i++){
      strip.setLedColor(i, 0, 0, 0);      
    }
      for (int i = 0; i < (LEDS_COUNT/3); i++) {
        strip.setLedColor(i, 255,255,0);
        strip.setBrightness(5);
        Serial.println("low");
        delay(0);
      }
      strip.show();
      delay(delayval);
  }
  else if (MicVolume > 1900 && MicVolume <= 2100){
    for (int i = 0; i < LEDS_COUNT+1; i++){
      strip.setLedColor(i, 0, 0, 0);      
    }

      for (int i = (LEDS_COUNT/3); i < (LEDS_COUNT/3*2); i++) {
        strip.setLedColor(i, 0,255,255);
        strip.setBrightness(5);
        Serial.println("med");
        delay(0);
      }
      strip.show();
      delay(delayval);
  }
  else if (MicVolume > 2100){
    for (int i = 0; i < LEDS_COUNT+1; i++){
      strip.setLedColor(i, 0, 0, 0);      
    }

      for (int i = (LEDS_COUNT/3*2); i < (LEDS_COUNT+1); i++) {
        strip.setLedColor(i,255,0,255);
        strip.setBrightness(5);
        Serial.println("high");
        delay(0);
      }
      strip.show();
      delay(delayval);
  }
  
}


