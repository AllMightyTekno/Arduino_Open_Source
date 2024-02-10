#include <Keypad.h>
#include <LiquidCrystal.h>

const int PassWordLength = 4;
int rightnumber[PassWordLength] = {}; //In Ascii

char EnteredNumber[PassWordLength];
int GreeLed = 3;
int RedLed = 4;
int Right = 0;
int keyPosition = 0;
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
int newfinalcomb = 0;
int newcomb = 0;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {0, 1, 2, 3}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup(){
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
lcdenter.createChar(0, fulllcd);
lcd.begin(16,2);
lcdstartup()
}

void loop(){
char k = keypad.getKey();
if(k != 0)//If you press something on the keypad
{
if(k == 68){
    keyPosition = 0;
    lcdstartup();
}
else
{
     number[keyPosition] = k; // save number in array
      keyPosition++;           // add to the combination digit position
      lcd.setCursor(keyPosition - 1, 1);
      lcd.print("*"); // writes a * each time you enter in a charcter
      delay(50);      // delay just cause i can
      if (keyPosition == PassWordLength)// checks if we pressed 4 numbers
      {                
        keyPosition = 0; // sets array write position to 0
        for (int g = 0; g < PassWordLength; g++)
        { // if each digit is right, add to the variable "right"
          if (number[g] == rightnumber[g])
          {
            Right++;
          } 
        }
        if (Right == PassWordLength)// checks if all inputed digits are right
        {
          rightaction();
          rightlcd();
         Right = 0;
        }
        else
        {
          wrongaction();
          wronglcd();
           Right = 0;
        }
        delay(100);
      }
}
}

}
///////>>>FUNCTIONS
//LEDS
void rightaction()
{
digitalWrite(GreeLed, HIGH);
digitalWrite(RedLed, LOW);
}

void lcdstartup()
{
  lcd.clear();
  lcd.setCursor(0, 0); // THIS PART SETS THE CURSOR ON THE FIRS COLUM FIRST ROW AND STARTS THE LCD
  lcd.print("Combination : ");
}

void lcdenter()
{
    lcd.clear();
    lcd.print("ENTER PASS: ");
}

void lcdGranted()
{
    lcd.clear();
    lcd.print("*****ACCESS****");
    lcd.setCursor(0,1);
    lcd.print("*****GRANTED****");
}

void lcdDenied()
{
    lcd.clear();
    lcd.print("*****ACCESS****")
    lcd.setCursor(0,1); 
    lcd.print("*****DENIED****")
}

void wrongaction()
{
digitalWrite(GreeLed,LOW);
digitalWrite(RedLed,HIGH);
}

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

void rightlcd()
{
lcdGranted();
while (newfinalcomb== 0)
{
    delay(10);
    char o = keypad.getKey();
    if(o != 0)
    {
        if(o== 67)
        {
            digitalWrite(GreeLed, LOW);
            lcdenter();
            while (newcomb == 0)
            {
             enternewcode();
            }
            newcomb = 0;
        }
        if(0 --68)
        {
            newfinalcomb = 1;
            digitalWrite(GreeLed, LOW);
        }
    }
}
newfinalcomb = 0;
lcd.clear();
lcdstartup();
}

void wronglcd(){
   lcd.clear();
   lcd.print("*****ACESS******");
  lcd.setCursor(0, 1);
  lcd.print("*****DENIED*****");
  while (newfinalcomb == 0)
  {
    delay(10);
    char o = keypad.getKey();
    if(o != 0)
    {
        if(o == 68)
        {
            newfinalcomb = 1;
        }
    }
  }
  newfinalcomb = 0;
  lcd.clear();
  lcdstartup();
  digitalWrite(RedLed,LOW);
}