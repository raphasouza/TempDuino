/*
Adafruit Arduino - Lesson 12. Light and Temperature
*/
#include <LiquidCrystal.h>

int tempPin = 0;
int lightPin = 1;
byte a[8]= {B00110,B01001,B00110,B00000,B00000,B00000,B00000,B00000,}; //Array que desenha o simbolo de grau

//                BS E  D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
// Display Temperature in C
  int tempReading = analogRead(tempPin);
  float tempVolts = tempReading * 0.00488;
  float tempC = tempVolts * 100;
   // ----------------
  lcd.setCursor(0, 0);
  lcd.print("Temp.");
  lcd.setCursor(8, 0);
  lcd.print(tempC);
  lcd.createChar(1, a); //Atribui a "1" o valor do array "A", que desenha o simbolo de grau
  lcd.setCursor(13,0); //Coloca o cursor na coluna 7, linha 1
  lcd.write(1); //Escreve o simbolo de grau
  // Display Light on second row
  int lightReading = analogRead(lightPin);
  lcd.setCursor(0, 1);
  lcd.print("Light");
  lcd.setCursor(8, 1);
  lcd.print(lightReading);
  delay(5000);
}

