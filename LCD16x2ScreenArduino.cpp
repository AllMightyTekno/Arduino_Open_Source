// Compatible with the Arduino IDE 1.0
// Library version:1.1
// Make sure to download Arduino incase you want to see this in action.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int age = 20;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Edit this depending on the size of your arduino screen

void setup()
{
  lcd.init(); // initialize/start the lcd
              // Print a message to the LCD.
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(3, 0); // This starts the text 3th colum but on the 1 colum
  lcd.print("I am learning Arduino, !");
  lcd.scrollDisplayLeft();
  lcd.setCursor(2, 1);
  lcd.print("Because I love Robotics");
  lcd.scrollDisplayLeft();
  delay(100);
}
