#define cross 13
#define red 35
#define yellow  29
#define green 33
#define button 2
#define Delay_time 500
#define Green_time 5
#define Yellow_time 3
#define Red_time 5

volatile int button_state = 0;
int i = 0;
int Flag; 
int Light_State; 


void setup() {
  // put your setup code here, to run once:
pinMode(cross,OUTPUT);
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
pinMode(button,INPUT);

attachInterrupt(0,setFlag,CHANGE);
Serial.begin(9600);

Flag=0;

}


void loop() {
  LOOP:
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(cross,LOW);
  for (i=0; i<=Green_time; i++)
  {delay(Delay_time);
  if(Flag==1){
    Light_State=1;
    pedestian();
    goto LOOP; 
  }
  }
digitalWrite(green,LOW);
digitalWrite(yellow,HIGH);
for(i=0; i <=Red_time; i++)
{delay(Delay_time);
if(Flag==1){
  Light_State=2;
  pedestian();
  goto LOOP;
}
}

digitalWrite(yellow,LOW);
digitalWrite(red,HIGH);
for (i=0; i<=Yellow_time; i++)
{delay(Delay_time);
if(Flag==1){
  Light_State=3;
  pedestian();
  goto LOOP;
}
}
}

void setFlag(void)
{
  Flag=1;
}

void pedestian(void){
switch (Light_State) {
  case 1:{ 
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(2000);

    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(cross,HIGH);
    delay(5000);
    
    break;
}
  case 2:{ 
    delay(500);
    delay(1000);
    

    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(cross,HIGH);
    delay(5000);
    break;
}
   case 3:{
   digitalWrite(red,HIGH);
   digitalWrite(cross,HIGH);
   delay(3000);
   break;
}
default:{};
}
for (i=0; i<=5; i++)
{
  digitalWrite(cross,LOW);
  delay(1000);
  digitalWrite(cross,HIGH);
  delay(1000);
}
Flag=0;
}
