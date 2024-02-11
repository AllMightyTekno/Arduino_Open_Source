// Compatible with the Arduino IDE 1.0
// Library version:1.1
// Make sure to download Arduino incase you want to see this in action.
//Here's the LCD Doc for further info https://docs.arduino.cc/learn/electronics/lcd-displays/
//Remember your lcd depending on the size has two inputs/paramaters ie (x,y) for each axis on this case our LCD is a 16x2 ie16 entries on both rows and 2 entries on each colums
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//LiquidCrystal_I2C lcd(0x27, 16, 2); // Edit this depending on the size of your arduino screen



void setup()
{
  lcd.begin(16,2);
   lcd.print(' WELCOME ');
  lcd.scrollDisplayLeft // initialize/start the lcd
  lcd.print(" TO THE LCD ");
   lcd.scrollDisplayLeft;            // Print a message to the LCD.
  lcd.backlight(); //This enables the lcd to have light emitting from it,if you don't need that you can simply remove this line.
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