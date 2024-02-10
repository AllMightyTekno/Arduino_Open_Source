// SECURITY LOCK USING KEYPAD

#include <Keypad.h>
#include <LiquidCrystal.h>

const int combinationlenght = 4;
int rightnumber[combinationlenght] = {49, 50, 51, 52}; // this codes for 1,2,3,4 in ASCII. Had to use it because the library stores the input in decimal ASCII intead of a number.

int newrightnumber[combinationlenght];
char number[combinationlenght];
int right = 0;
int green = 4;
int red = 5;
int newcomb = 0;
byte fulllcd[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
};
int newfinalcomb = 0;
int kposition = 0;
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {0, 1, 2, 3}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup()
{
  // put your setup code here, to run once:
  // Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  lcd.createChar(0, fulllcd);
  lcd.begin(16, 2);
  lcdstartup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  char k = keypad.getKey();
  if (k != 0)
  { // if you press something
    if (k == 68)
    {
      kposition = 0;
      lcdstartup();
    }
    else
    {
      number[kposition] = k; // save number in array
      kposition++;           // add to the combination digit position
      lcd.setCursor(kposition - 1, 1);
      lcd.print("*"); // writes a * each time you enter in a charcter
      delay(50);      // delay just cause i can
      if (kposition == combinationlenght)// checks if we pressed 4 numbers
      {                
        kposition = 0; // sets array write position to 0
        for (int g = 0; g < combinationlenght; g++)
        { // if each digit is right, add to the variable "right"
          if (number[g] == rightnumber[g])
          {
            right++;
          } 
        }
        if (right == combinationlenght)// checks if all inputed digits are right
        {
          rightaction();
          rightlcd();
          right = 0;
        }
        else
        {
          wrongaction();
          wronglcd();
          right = 0;
        }
        delay(100);
      }
    }
  }
}
// LEDS
void rightaction()
{
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
}
void wrongaction()
{
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
}

void lcdstartup()
{
  lcd.clear();
  lcd.setCursor(0, 0); // THIS PART SETS THE CURSOR ON THE FIRS COLUM FIRST ROW AND STARTS THE LCD
  lcd.print("Combination : ");
}
void lcdenter()
{ // ENTERS THE PASSWORD
  lcd.clear();
  lcd.print("Enter new :");
}
void lcdgranted()
{ // IF RIGHT PASSWORD HAS BEEN
  lcd.clear();
  lcd.print("*****ACESS******");
  lcd.setCursor(0, 1);
  lcd.print("****GRANTED*****");
}

void rightlcd()
{
  lcdgranted();
  while (newfinalcomb == 0)
  {
    delay(10);
    char o = keypad.getKey();
    if (o != 0)
    {
      if (o == 67)
      {
        digitalWrite(green, LOW);
        lcdenter();
        while (newcomb == 0)
        {
          enternewcode();
        }
        newcomb = 0;
      }
      if (o == 68)
      {
        newfinalcomb = 1;
        digitalWrite(green, LOW);
      }
    }
  }
  newfinalcomb = 0;
  lcd.clear();
  lcdstartup();
}

// CREATES A NEW KEY
void enternewcode()
{
  char newk = keypad.getKey();
  if (newk != 0)
  {
    newrightnumber[kposition] = newk;
    kposition++;
    lcd.setCursor(kposition, 1);
    lcd.print(newk);
    if (newk == 68)
    {
      lcd.setCursor(0, 1);
      lcd.print("        ");
      kposition = 0;
    }
    if (kposition == combinationlenght)
    {
      lcd.setCursor(kposition + 1, 1);
      lcd.write(byte(0));
      delay(1000);
      kposition = 0;
      checknewcode();
    }
  }
}

// CHECKS NEW KEY/CODE
void checknewcode()
{
  lcd.clear();
  lcd.print("Are you sure ?");
  while (newcomb == 0)
  {
    char newc = keypad.getKey();
    if (newc != 0)
    {
      if (newc == 65)
      {
        lcd.clear();
        lcd.print("New code");
        lcd.setCursor(0, 1);
        lcd.print("Accepted");
        newcomb = 1;
        newfinalcomb = 1;
        for (int j = 0; j < combinationlenght; j++)
        {
          rightnumber[j] = newrightnumber[j];
        }
        kposition = 0;
        delay(1500);
      }
      if (newc == 66)
      {
        delay(10);
        lcdgranted();
        newcomb = 1;
      }
    }
  }
}
// WRONG PASSWORD
void wronglcd()
{
  lcd.clear();
  lcd.print("*****ACESS******");
  lcd.setCursor(0, 1);
  lcd.print("*****DENIED*****");
  while (newfinalcomb == 0)
  {
    delay(10);
    char o = keypad.getKey();
    if (o != 0)
    {
      if (o == 68)
      {
        newfinalcomb = 1;
      }
    }
  }
  newfinalcomb = 0;
  lcd.clear();
  lcdstartup();
  digitalWrite(red, LOW);
}