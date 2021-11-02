
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Biblioteca para LCD 
// Ligação: o pino SDA está conectado ao A4 e o pino SCL ao A5.
// Conecte ao LCD via I2C, endereço padrão 0x27 (A0-A2 sem jumpers) 
// Inicializa o display no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int val = 0 ;

void setup()
{
  Serial.begin(9600);
  // Inicializa o display LCD 16x2
  lcd.begin (16, 2);
  // Liga a luz de fundo do LCD
  lcd.setBacklight(HIGH); 
  pinMode(3, INPUT); // pino de saída do sensor pir conectado
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(4, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Sistema de irrigação ");
}

void loop()
{
  val = digitalRead(3); // soil moisture sensor output pin connected
  Serial.println(val); // veja o valor no monitor serial no Arduino IDE
  delay(1000);

  if (val == 1 )
  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    lcd.setCursor(0, 1);
    lcd.print(" PUMP ON ");
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    lcd.setCursor(0, 1);
    lcd.print(" PUMP OFF ");
  }
}
