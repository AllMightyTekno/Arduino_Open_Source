///DOC for Servo Motor https://docs.arduino.cc/learn/electronics/servo-motors/
//DOC for Water Sensor https://arduinogetstarted.com/tutorials/arduino-water-sensor
//My Documents can be forked and updated I would greatly appreciate it


#include <Servo.h>

Servo myservo;
int pos = 0; 

int WaterSignalPin = A2;
int WaterPowerPin = 4;
int GreenLed = 3;
int RedLed = 2;
int WaterValue;

/// OUR CONSTANT INT(UNCHANCHABLE)
const int HighThreshold = 900;
const int LowThreshold = 500;

  void setup()
{
myservo.attach(9) //attaches the servo to pin 9 to the servo object

    digitalWrite(RedLed, HIGH);
    digitalWrite(GreenLed, LOW);
    Serial.begin(9600);
    pinMode(RedLed, OUTPUT);
}

void loop()
{
    digitalWrite(WaterPowerPin, HIGH);
    WaterValue = analogRead(WaterSignalPin);
    if (WaterValue <= LowThreshold)
    {
        digitalWrite(RedLed, HIGH);
        Serial.print(" LOW WATER, VALUE : ");
        Serial.print(WaterValue);
        for (pos = 0; pos <=180; pos+= 180) {
            myservo.write(pos); //tell servo to go to position in variable 'pos'
            delay(10000);
            pos= 0 
            myservo.write(pos);
        }
    }

    else if (WaterValue <= HighThreshold)
    {
        digitalWrite(GreenLed, HIGH);
        Serial.print(" ENOUGH WATER, VALUE : ");
        Serial.print(WaterValue);
    }
    else 
    {
       digitalWrite(GreenLed,LOW);
       digitalWrite(RedLed, LOW);
       Serial.println(" WATER VALUE IS MEDUIM ");
    }
      delay(1000); 
}