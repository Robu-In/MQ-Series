#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define LED 3
#define sensorAnalog A1
 
void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(LED, OUTPUT);

  lcd.setCursor(3,0);
  lcd.print("MQ3 Warming Up");

  delay(10000);
}

void loop() {
  int analog = analogRead(sensorAnalog);
 
  lcd.setCursor(0,0);
  lcd.print("CO PPM:");
  lcd.setCursor(0,1);
  lcd.print(analog);

  if (analog >=400) {
    digitalWrite(LED, HIGH);
  }

  else {
    digitalWrite(LED, LOW);
  }

  delay(300);
  lcd.clear();
}

