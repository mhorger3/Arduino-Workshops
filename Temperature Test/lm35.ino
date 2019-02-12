
#include <LiquidCrystal.h>         
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Digital pins to which you connect the LCD
const int inPin = 1;                   // A0 is where you connect the sensor
void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  int value = analogRead(inPin); // read the value from the sensor
  lcd.setCursor(0,1);
  float millivolts = (value / 1024.0) * 5000; 
  float celsius = millivolts / 10;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(celsius);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print((celsius * 9)/5 + 32); //turning the celsius into fahrehait
  lcd.print("F");
  delay(1000);
}
