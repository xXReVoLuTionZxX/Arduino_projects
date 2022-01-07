
#include "LiquidCrystal.h"
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int PWM_pin = 13;        //  one of 3, 5, 6, 9, 10, 11
int DutyClycle;
const byte interruptPin1 = 18; 
const byte interruptPin2 = 20;
volatile byte state2 = 0;
volatile byte state3 = 255;
void setup() 
  {
        lcd.begin(16, 2);
        pinMode(PWM_pin, OUTPUT);
        attachInterrupt(digitalPinToInterrupt(interruptPin1), blink3, CHANGE);
        attachInterrupt(digitalPinToInterrupt(interruptPin2), blink4, CHANGE);
        Serial.begin(9600);
  }
void loop() 
  {  for(int i=0;i<=255;i+=25.5)
      { int duty_cycle = i;     //  between 0 and 255
         analogWrite( PWM_pin, duty_cycle ); //Snd the command to the motor
         
         DutyClycle=(100 * i)/255;
         lcd.print("i= ");
         lcd.print(i);
         lcd.setCursor(0,1);
         lcd.print(" Duty Cycle=");
         lcd.print(DutyClycle);
         lcd.print("%");
         delay(4000); //Wait one second each speed
         lcd.clear();
   }
  }

  void blink3() {
  state2= 0;
  analogWrite(PWM_pin, state2);
}
void blink4() {
  state3= 255;
  analogWrite(PWM_pin, state3);
}
