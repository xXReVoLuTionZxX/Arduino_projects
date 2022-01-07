
//declare LEDs
int greenLed = 11;
int orangeLed = 12;
int redLed = 13;

//declare Push button
int pushButton = 48;

int readPushbutton = 0;

void setup()
{
  pinMode(greenLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  //pinMode(pushButton, INPUT);
 
  //Turn the LEDs off
  digitalWrite(greenLed, LOW);
  digitalWrite(orangeLed, LOW);
  digitalWrite(redLed, LOW);
  
  //setting the buttons to input
  pinMode(pushButton, INPUT);
  
  
  //for the serial monitor
  Serial.begin(9600);
}

void loop()
{
  
  int readPushbutton = digitalRead(pushButton);
  
  if (readPushbutton == 0 ) {
      digitalWrite(greenLed, HIGH);
      digitalWrite(orangeLed, LOW);
      digitalWrite(redLed, LOW);  
      delay(1000);
        
    }
    else if (readPushbutton == 1){
        Serial.println("PEDESTRIAN WAITING");
        digitalWrite(greenLed,LOW);
      digitalWrite(orangeLed,HIGH);
        digitalWrite(redLed, LOW); 
      delay(2000);
      
        digitalWrite(greenLed,LOW);
      digitalWrite(orangeLed,LOW);
      digitalWrite(redLed,HIGH);
      Serial.println("PEDESTRIAN CROSSING");
      delay(5000);
            
    }
}
