// THIS CODE IS A SMALL SCALE EXAMPLE OF WHAT HAPPENS IN AUTOMATIC STREET LIGHTS
// YOU CAN USE THIS CODE FOR ANY PROJECTS
//Here's the doc on PhototResistors on the arduino website 

int photoResistor = A2;
int valueOflight;
int StreetLight = 7;

void setup()
{
  // put your setup code here, to run once:
  pinMode(photoResistor, INPUT);
  Serial.begin(9600);
  pinMode(StreetLight, OUTPUT);
}

void loop()
{
  // THIS CODE CONTROLS WHAT HAPPENS WHEN A CERTAIN LIGHT INTENSITY TOUCHES THE PHOTORESISTOR
  valueOflight = analogRead(photoResistor);
  Serial.print("VALUE OF LIGHT IS:  ");
  Serial.println(valueOflight);
  if (valueOflight > 90) // If light intensity is < 90, it's evening/night time and lights are switched on
  {
    digitalWrite(StreetLight, HIGH);
    Serial.print(' IT IS NIGHT TIME AND LIGHTS ARE SWITCHED ON ')
  }
  else
       // Else it's day outside and lights are turned off
    {
      digitalWrite(StreetLight, LOW);
      Serial.print(" IT'S DAY OUTSIDE AND LIGHTS ARE SWITCHED OFF ")
    }
}
