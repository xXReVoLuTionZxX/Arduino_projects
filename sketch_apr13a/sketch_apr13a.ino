//Street 1
#define cross 26
#define red 35
#define yellow 29
#define green 33
#define button 39

//Street 2
#define cross_2 27
#define red_2 31
#define yellow_2 45
#define green_2 43
#define button_2 30 


#define Delay_time 500
#define Green_time 5
#define Yellow_time 3
#define Red_time 5


volatile int button_state_1 = 0;
volatile int button_state_2 = 0;
int i = 0;
int Flag1;
int Flag2;
int Light_state_1;
int Light_state_2;

void setup() {
  //light 1
  pinMode(cross, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);

  //light 2
  pinMode(cross_2, OUTPUT);
  pinMode(red_2, OUTPUT);
  pinMode(yellow_2, OUTPUT);
  pinMode(green_2, OUTPUT);
  pinMode(button_2, INPUT);
  


  attachInterrupt(0,SetFlag1, CHANGE);
  attachInterrupt(1,SetFlag2, CHANGE);

  Serial.begin(9600);

  Flag1 = 0;
  Flag2 = 0;
}

void loop() {
  LOOP:
       digitalWrite(red,LOW);       //Light 1 is Green, whilst Light 2 is Red
       digitalWrite(yellow,LOW);
       digitalWrite(green, HIGH);
       digitalWrite(cross,LOW);

       digitalWrite(red_2,HIGH);       
       digitalWrite(yellow_2,LOW);
       digitalWrite(green_2, LOW);
       digitalWrite(cross_2,LOW);
       
       for (i=0;i<=Green_time;i++)
        {delay(Delay_time);
        if(Flag1 == 1) {
          Light_state_1 = 1;
          Pedestrian1();
          goto LOOP;
        }
        else if(Flag2 == 1){
          Light_state_2 = 3;
          Pedestrian2();
          goto LOOP;
        }
       }
       //yellow state for Light 1, Green State for Light 2
       digitalWrite(green,LOW);
       digitalWrite(yellow,HIGH);

       digitalWrite(green_2,HIGH);
       digitalWrite(red_2,LOW);
       
       for (i=0;i<Red_time;i++)
         {delay(Delay_time);
         if(Flag1==1) {
          Light_state_1=2;
          Pedestrian1();
          goto LOOP;
         }
         else if(Flag2 == 1){
          Light_state_2 = 1;
          Pedestrian2();
          goto LOOP;
        }
        }
        //red state for Light 1, Yellow State for Light 2
        digitalWrite(yellow,LOW);
        digitalWrite(red, HIGH);

        digitalWrite(green_2,LOW);
        digitalWrite(yellow_2,HIGH);
        
        for(i=0;i<=Red_time;i++)
          {delay(Delay_time);
          if(Flag1==1) {
            Light_state_1=3;
            Pedestrian1();
            goto LOOP;
          }
          else if(Flag2 == 1){
          Light_state_2 = 2;
          Pedestrian2();
          goto LOOP;
        }
          }

}

void SetFlag1(void){
  Flag1 = 1;
}

void SetFlag2(void) {
  Flag2 = 1;
}

void Pedestrian1(void) {
  switch (Light_state_1) {  //Green light for light 1
    case 1:{
      digitalWrite(green,LOW);
      digitalWrite(yellow,HIGH);
      delay(2000);
      //Set Red on and Pedestrian on
      digitalWrite(yellow,LOW);
      digitalWrite(red,HIGH);
      digitalWrite(cross,HIGH);
      delay(5000);

      break;
    }
    case 2:{
      delay(500);
      delay(1000);
      //set Red on and Pedestrian on
      digitalWrite(yellow,LOW);
      digitalWrite(red,HIGH);
      digitalWrite(cross,HIGH);
      delay(5000);

      break;
  }
  case 3:{
    digitalWrite(red,HIGH);
    digitalWrite(cross, HIGH);
    delay(3000);
    break;
  }
  default:{};
}
  for (i=0;i<=5;i++)
  {digitalWrite(cross,LOW);
  delay(1000);
  digitalWrite(cross,HIGH);
  delay(1000);
  }
  Flag1=0;
}
void Pedestrian2(void) {
  switch (Light_state_2) {
    case 1:{
      digitalWrite(green_2,LOW);
      digitalWrite(yellow_2,HIGH);
      delay(2000);
      //Set Red on and Pedestrian on
      digitalWrite(yellow_2,LOW);
      digitalWrite(red_2,HIGH);
      digitalWrite(cross_2,HIGH);
      delay(5000);

      break;
    }
    case 2:{
      delay(500);
      delay(1000);
      //set Red on and Pedestrian on
      digitalWrite(yellow_2,LOW);
      digitalWrite(red_2,HIGH);
      digitalWrite(cross_2,HIGH);
      delay(5000);

      break;
  }
  case 3:{
    digitalWrite(red_2,HIGH);
    digitalWrite(cross_2, HIGH);
    delay(3000);
    break;
  }
  default:{};
}
  for (i=0;i<=5;i++)
  {digitalWrite(cross_2,LOW);
  delay(1000);
  digitalWrite(cross_2,HIGH);
  delay(1000);
  }
  Flag2=0;
}
