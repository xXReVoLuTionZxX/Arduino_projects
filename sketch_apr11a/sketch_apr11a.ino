// One digit 7 segment LED display demo.
// Displays digit 0 - 9 and decimal point

int segPins[] = {32, 34, 36, 38, 40, 42, 44, 46 };   // { a b c d e f g . )

byte segCode[11][8] = {
//  a  b  c  d  e  f  g  .
  { 1, 1, 1, 1, 1, 1, 0, 0},  // 0
  { 0, 1, 1, 0, 0, 0, 0, 0},  // 1
  { 1, 1, 0, 1, 1, 0, 1, 0},  // 2
  { 1, 1, 1, 1, 0, 0, 1, 0},  // 3
  { 0, 1, 1, 0, 0, 1, 1, 0},  // 4
  { 1, 0, 1, 1, 0, 1, 1, 0},  // 5
  { 1, 0, 1, 1, 1, 1, 1, 0},  // 6
  { 1, 1, 1, 0, 0, 0, 0, 0},  // 7
  { 1, 1, 1, 1, 1, 1, 1, 0},  // 8
  { 1, 1, 1, 1, 0, 1, 1, 0},  // 9
  { 0, 0, 0, 0, 0, 0, 0, 1}   // .
};


void displayDigit(int digit)
{
  for (int i=0; i < 8; i++)
  {
    digitalWrite(segPins[i], segCode[digit][i]);
  }
}

//***************************************************************************
//******************************************************************************
void setup()
{
  for (int i=0; i < 8; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }

 }

//******************************************************************************
//******************************************************************************
void loop()
{
   for (int n = 0; n < 11; n++)    // display digits 0 - 9 and decimal point
  {
     displayDigit(n);
     delay(1000);
  }

}