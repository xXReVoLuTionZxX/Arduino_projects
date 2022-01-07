//street B 
int green = 33;
int orange = 29;
int red = 35;
volatile int btnPedestrian = 28; 
int pedestrianLight= 26;

//avenue A
int green2 = 41;
int orange2 = 43;
int red2 = 31;
volatile int btnPedestrian2 = 30; 
int pedestrianLight2= 47; 

//avenue A 

void setup() {
  // put your setup code here, to run once:
pinMode(green, OUTPUT);
pinMode(orange, OUTPUT);
pinMode(red, OUTPUT);

pinMode(green2, OUTPUT);
pinMode(orange2, OUTPUT);
pinMode(red2, OUTPUT);

digitalWrite(green,LOW);
digitalWrite(orange,LOW);
digitalWrite(red,LOW);
pinMode(btnPedestrian, INPUT);

digitalWrite(green2,LOW);
digitalWrite(orange2,LOW);
digitalWrite(red2,LOW);
pinMode(btnPedestrian2, INPUT);

Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:

greenLight();


}

void greenLight(){
  
  for (int i = 1; i < 60; i++){
    int state = digitalRead(btnPedestrian);
    int state2 = digitalRead(btnPedestrian2);

    if (state && state2  == 0) {
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
      digitalWrite(pedestrianLight, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(pedestrianLight, LOW);
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
      digitalWrite(pedestrianLight2, HIGH);
      delay(4000);
      digitalWrite(pedestrianLight2, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(pedestrianLight, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(pedestrianLight, LOW);
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
      digitalWrite(pedestrianLight2, HIGH);
      delay(4000);
      digitalWrite(pedestrianLight2, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(pedestrianLight, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(pedestrianLight, LOW);
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
      digitalWrite(pedestrianLight2, HIGH);
      delay(4000);
      digitalWrite(pedestrianLight2, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(red, LOW);
      Serial.println("\nRED2 goes off to finish the 3rd loop");
      digitalWrite(orange2, LOW);
      digitalWrite(green2, LOW);
      Serial.println("\nGREEN1 goes off to finish 3rd loop");     
      return;
    }
    else if (state2 == 1){
     digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(pedestrianLight, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(pedestrianLight, LOW);
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
      digitalWrite(pedestrianLight2, HIGH);
      delay(4000);
      digitalWrite(pedestrianLight2, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(pedestrianLight, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(pedestrianLight, LOW);
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
      digitalWrite(pedestrianLight2, HIGH);
      delay(4000);
      digitalWrite(pedestrianLight2, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      Serial.println("\nGREEN1");
      Serial.print("PEDESTRIAN CROSSING");
      digitalWrite(pedestrianLight, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      Serial.println("\nRED2");      
      delay(5000);
      digitalWrite(pedestrianLight, LOW);
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
      digitalWrite(pedestrianLight2, HIGH);
      delay(4000);
      digitalWrite(pedestrianLight2, LOW);
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


 
