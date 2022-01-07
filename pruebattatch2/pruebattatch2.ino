const byte ledPin = 13;
const byte ledPin2 = 12;
const byte interruptPin = 2;
volatile byte state = LOW;
int green = 33;
int orange = 29;
int red = 35;

int green2 = 41;
int orange2 = 43;
int red2 = 31;
int bottomToStart = 7;

 
void setup() {
   pinMode(ledPin, OUTPUT);
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
   pinMode(green2, OUTPUT);
pinMode(orange2, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(green, OUTPUT);
pinMode(orange, OUTPUT);
pinMode(red, OUTPUT);
pinMode(bottomToStart, INPUT);

digitalWrite(green,LOW);
digitalWrite(orange,LOW);
digitalWrite(red,LOW);
digitalWrite(green2,LOW);
digitalWrite(orange2,LOW);
digitalWrite(red2,LOW);

 
Serial.begin(9600);
}
void loop() {
  Serial.print("estoy aqui en loop");
   //digitalWrite(green2, state);
   
   for (int i = 1; i < 60; i++){
    int statebtn = digitalRead(bottomToStart);
    //int state2btn = digitalRead(btnPedestrian);

    if (state  == 0) {
      Serial.print(i);
      delay(1000);
      Serial.print(",");
      //return;
     }
    else if (state == 1){
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(ledPin, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(ledPin, LOW);
      digitalWrite(green, LOW);
      digitalWrite(orange, HIGH);
      Serial.println("\nORANGE");
      digitalWrite(red2, LOW);
      digitalWrite(orange2, HIGH);
      Serial.println("\nORANGE2");
      delay(1000);
      digitalWrite(orange, LOW);
      digitalWrite(red, HIGH);
      Serial.println("\nRED2");
      digitalWrite(orange2, LOW);
      digitalWrite(green2, HIGH);
      Serial.println("\nGREEN2");
      Serial.print("PEDESTRIAN CROSSING2");
      digitalWrite(ledPin2, HIGH);
      delay(4000);
      digitalWrite(ledPin2, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(ledPin, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(ledPin, LOW);
      digitalWrite(green, LOW);
      digitalWrite(orange, HIGH);
      Serial.println("\nORANGE");
      digitalWrite(red2, LOW);
      digitalWrite(orange2, HIGH);
      Serial.println("\nORANGE2");
      delay(1000);
      digitalWrite(orange, LOW);
      digitalWrite(red, HIGH);
      Serial.println("\nRED2");
      digitalWrite(orange2, LOW);
      digitalWrite(green2, HIGH);
      Serial.println("\nGREEN2");
      Serial.print("PEDESTRIAN CROSSING2");
      digitalWrite(ledPin2, HIGH);
      delay(4000);
      digitalWrite(ledPin2, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(ledPin, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(ledPin, LOW);
      digitalWrite(green, LOW);
      digitalWrite(orange, HIGH);
      Serial.println("\nORANGE");
      digitalWrite(red2, LOW);
      digitalWrite(orange2, HIGH);
      Serial.println("\nORANGE2");
      delay(1000);
      digitalWrite(orange, LOW);
      digitalWrite(red, HIGH);
      Serial.println("\nRED2");
      digitalWrite(orange2, LOW);
      digitalWrite(green2, HIGH);
      Serial.println("\nGREEN2");
      Serial.print("PEDESTRIAN CROSSING2");
      digitalWrite(ledPin2, HIGH);
      delay(4000);
      digitalWrite(ledPin2, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(red, LOW);
      Serial.println("\nRED2 goes off to finish the 3rd loop");
      digitalWrite(orange2, LOW);
      digitalWrite(green2, LOW);
      Serial.println("\nGREEN1 goes off to finish 3rd loop");     
      return;
    }
}
} 
void blink() {
  // state = !state;
  //if (state == 1){
   // digitalWrite(green2, state);
    //  digitalWrite(red2, state);   
  //}
}
