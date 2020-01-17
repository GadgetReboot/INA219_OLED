// INA219 Current Sensor with OLED Display for Arduino Uno
//
// This sketch was modified from the Adafruit INA219 library example
//
// Gadget Reboot
//
// Required Libraries
// https://github.com/adafruit/Adafruit_INA219
// https://github.com/adafruit/Adafruit_SSD1306

#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Adafruit_SSD1306.h>
Adafruit_INA219 ina219;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

float shuntvoltage = 0;
float busvoltage = 0;
float current_mA = 0;
float power_mW = 0;


void setup() {

  // initialize ina219 with default measurement range of 32V, 2A
  ina219.begin();

  // ina219.setCalibration_32V_2A();    // set measurement range to 32V, 2A
  // ina219.setCalibration_32V_1A();    // set measurement range to 32V, 1A
  // ina219.setCalibration_16V_400mA(); // set measurement range to 16V, 400mA

  // initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.display();

}

void loop() {

  // read data from ina219
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();

  // show data on OLED
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print(busvoltage);
  display.print(" V");

  display.setCursor(50, 0);
  display.print(shuntvoltage);
  display.print(" mV");

  display.setCursor(0, 10);
  display.print(current_mA);
  display.print(" mA");

  display.setCursor(0, 20);
  display.print(power_mW);
  display.print(" mW");

  display.display();

}
