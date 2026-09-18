#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS    5
#define TFT_DC    16
#define TFT_RST   17

#define BTN_UP    12
#define BTN_DOWN  13
#define BTN_LEFT  14
#define BTN_RIGHT 27
#define BTN_A     25
#define BTN_B     26

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const int buttons[] = {BTN_UP, BTN_DOWN, BTN_LEFT, BTN_RIGHT, BTN_A, BTN_B};
const char* btnNames[] = {"UP", "DOWN", "LEFT", "RIGHT", "A", "B"};
int lastState[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 6; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  tft.init(170, 320);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 20);
  tft.println("ESP32 Handheld Test");

  tft.setTextSize(1);
  tft.setCursor(20, 60);
  tft.println("Press any button...");
}

void loop() {
  for (int i = 0; i < 6; i++) {
    int state = digitalRead(buttons[i]);
    
    if (state != lastState[i]) {
      if (state == LOW) {
        tft.fillRect(20, 100, 200, 30, ST77XX_BLACK);
        tft.setTextSize(2);
        tft.setTextColor(ST77XX_GREEN);
        tft.setCursor(20, 100);
        tft.print("Pressed: ");
        tft.print(btnNames[i]);

        Serial.print("Button pressed: ");
        Serial.println(btnNames[i]);
      }
      lastState[i] = state;
      delay(20);
    }
  }
}

##lowk had to google smn every line
##if it doesnt work ill just change it as i go