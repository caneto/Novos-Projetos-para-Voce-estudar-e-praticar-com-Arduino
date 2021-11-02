#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Illuminance");
}
 
void loop()
{
  //lcd.clear();
  float volts = analogRead(A0) * 5.0 / 1024.0;
  float amps = volts / 10000.0; // across 10,000 Ohms
  float microamps = amps * 1000000;
  float lux = microamps * 2.0;
  lcd.setCursor(0, 1);
  lcd.print(lux);
  lcd.print(" lux");
  delay(750);
}
