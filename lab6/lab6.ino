
String msgType= "Type one of the following CW, CCW, STP";
String operation; 

#define IN1  3
#define IN2  4
#define IN3  5
#define IN4  6
int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time;
unsigned long currentMillis ;
int steps_left=4095;
int pasos; 
String mynumber;
long time;
void setup()
{
Serial.begin(9600);// set The BAUD rate to 115,200
pinMode(IN1, OUTPUT); //Phase 1
pinMode(IN2, OUTPUT); //Phase 1 Negate
pinMode(IN3, OUTPUT); //Phase 2
pinMode(IN4, OUTPUT); //Phase 2 Negate
delay(1000);

}
void loop()
{
Serial.println(msgType);
while (Serial.available()==0){
  
}
operation=Serial.readString();
 
  if (operation == "cw\n") {
   Direction=!Direction;
  Serial.println(Direction);
 while (Serial.available()==0) {
  
  Serial.println("clockwise");
   while(steps_left>0)
    {
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
          {
          stepper(1); 
          time=time+micros()-last_time;
          last_time=micros();
          steps_left--;
          }
  
    }
    Serial.println(time);
    Serial.println("Wait...!");
    Serial.print("steps = ");
    Serial.println(steps_left);
    steps_left=4095;
 
 }
 Serial.println("press esc to stop");
 operation == Serial.readString();
 
  }

  if (operation == "ccw\n") {
  Direction=!Direction;
  Serial.println(Direction);
 while (Serial.available()==0) {
  
  Serial.println("counter-clockwise");
   while(steps_left>0)
    {
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
          {
          stepper(1); 
          time=time+micros()-last_time;
          last_time=micros();
          steps_left--;
          }
    }
    
    Serial.println(time);
    Serial.println("Wait...!");
    Serial.print("steps = ");
    Serial.println(steps_left);
     steps_left=4095;
  
 }
 Serial.println("press esc to stop");
 operation == Serial.readString();
 
  }

 if (operation == "stp\n") {
  Direction=!Direction;
  Serial.println("enter number of steps"); 
  while (Serial.available()==0) {
   }
   mynumber=Serial.readString();
  int pasos=mynumber.toInt();
  Serial.println("the number of steps insert are");
  Serial.print(pasos);
  
   while(pasos>0)
    {
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
          {
          stepper(1); 
          time=time+micros()-last_time;
          last_time=micros();
          pasos--;
          }
    }
    Serial.println(time);
    Serial.println("Wait...!");
    Serial.print("steps = ");
    Serial.println(pasos);
   
  }


}
 
   


void stepper(int xw){
  for (int x=0;x<xw;x++)
      {
       
      switch(Steps){
       case 0:
       
           digitalWrite(IN1, LOW); 
           digitalWrite(IN2, LOW);
           digitalWrite(IN3, LOW);
           digitalWrite(IN4, HIGH);
        break; 
     case 1:
       
          digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, HIGH);
       break; 
     case 2:
        
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
     case 3:
        
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
     case 4:
         
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
     case 5:
      
       digitalWrite(IN1, HIGH); 
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
     break; 
     case 6:
        
       digitalWrite(IN1, HIGH); 
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
     break; 
     case 7:
      
       digitalWrite(IN1, HIGH); 
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);
       break; 
     default:
      
       digitalWrite(IN1, LOW); 
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
     break; 
    }
   SetDirection();
  }
} 

void SetDirection(){
if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }
}
