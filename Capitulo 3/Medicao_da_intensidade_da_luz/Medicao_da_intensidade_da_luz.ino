#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int temt6000Pin = A0;

float light;
int light_value;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(temt6000Pin, INPUT); //pino de dados para sensor de luz ambiente
  lcd.setCursor(0, 0);
  lcd.print("Light Intensity");
}

void loop() {
   int light_value = analogRead(temt6000Pin);
   light = light_value * 0.0976;// cálculo de porcentagem
   Serial.println(light);
   lcd.setCursor(0, 1);
   lcd.print(light);
   lcd.print(" %");
   delay(500);
}
