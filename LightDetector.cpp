//THIS CODE IS A SMALL SCALE EXAMPLE OF WHAT HAPPENS IN AUTOMATIC STREET LIGHTS
//YOU CAN USE THIS CODE FOR ANY PROJECTS

int photoResistor = A2;
int valueOflight;
int LED=7;
int LED2=8;


void setup() {
  // put your setup code here, to run once:
  pinMode(photoResistor,INPUT);
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
    pinMode(LED2,OUTPUT);
  
}

void loop() {
  // pTHIS CODE CONTROLS WHAT HAPPENS WHEN A CERTAIN LIGHT INTENSITY TOUCHES THE PHOTORESISTOR
  valueOflight = analogRead(photoResistor);
  Serial.print("VALUE OF LIGHT IS:  ");
  Serial.println(valueOflight);
  if(valueOflight>90) //If light intensity is < 90, it's evening/night time and lights are switched on 
   {
     digitalWrite(LED, HIGH);
     digitalWrite(LED2, HIGH);
  } else 7//Else it's day outside and lights are turned off 
  {
      digitalWrite(LED,LOW);
      digitalWrite(LED2,LOW); 
    }
    

  
  
}
