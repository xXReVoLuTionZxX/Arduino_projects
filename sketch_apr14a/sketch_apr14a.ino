//set de variables para la primera luz
int red_1 = 35;
int yellow_1 = 29;
int green_1 = 33;
int cross_1 = 35;
int button_1 = 28;   

//set de variables para la segunda luz
int red_2 = 31;
int yellow_2 =43;
int green_2 = 41;
int cross_2 = 47;
int button_2 = 30;   

int counter = 0;

int buttonpressed_1 = 0;
int buttonpressed_2 = 0;

void setup()
{
  //Light 1
  pinMode(red_1, OUTPUT);
  pinMode(yellow_1, OUTPUT);
  pinMode(green_1, OUTPUT);
  pinMode(cross_1, OUTPUT);
  pinMode(button_1, OUTPUT);
  digitalWrite(green_1, HIGH);
  attachInterrupt(digitalPinToInterrupt(2), blink1, RISING);
  
  //Light 2
  pinMode(red_2, OUTPUT);
  pinMode(yellow_2, OUTPUT);
  pinMode(green_2, OUTPUT);
  pinMode(cross_2, OUTPUT);
  pinMode(button_2, OUTPUT);
  digitalWrite(red_2, HIGH);
  attachInterrupt(digitalPinToInterrupt(3), blink2, RISISNG);
} 
void led_set_1(int 35, int 29, int 33, int 35)
  {
    digitalWrite(red_1, 11);
    digitalWrite(yellow_1, 12);
    digitalWrite(green_1, 13);
    digitalWrite(cross_1, 14);
  }
void led_set_2(int 31, int 43, int 41, int 47)
  {
    digitalWrite(red_2, 11);
    digitalWrite(yellow_2, 12);
    digitalWrite(green_2, 13);
    digitalWrite(cross_2, 14);
  }

void blink1() {
    buttonpressed_1 = 1;
  }
  
void blink2() {
    buttonpressed_2 = 1;
  } 
  
void loop() {
  while (counter < 3)
    {
      changeLights();
      counter = counter + 1;
    }
  }
  
void changeLights() {
    led_set_1(0,0,1,0);
    led_set_2(1,0,0,0);
    if(buttonpressed_2 == 1)
    {
      led_set_2(1,0,0,1);
      led_set_1(0,0,1,0);
      delay (5000);
      for(int i =0; i<10; i++)
        {
          digitalWrite(cross_2, HIGH);
          delay(1000);
          digitalWrite(cross_2, LOW);
          delay(1000);
        }
      buttonpressed_2 = 0;
      counter = 1;
    }
    
    delay(5000);
    
    led_set_1(0,1,0,0);
    
    delay(5000);
    
    led_set_2(0,0,1,0);
    led_set_1(1,0,0,0);
    if(buttonpressed_1 == 1)
    {
      led_set_1(1,0,0,1);
      led_set_2(0,0,1,0);
      delay(5000);
      for(int i =0; i<10; i++)
      {
        digitalWrite(cross_1, HIGH);
        delay(1000);
        digitalWrite(cross_1, LOW);
        delay(1000);
      }
      buttonpressed_1 = 0;
      counter = 1;
    }
    delay(5000);
    led_set_2(0,1,0,0);
    delay(5000);
  }
