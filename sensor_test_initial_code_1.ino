
int IR1 = A0;
int IR2 = A1;
int IR3 = A2;
int IR4 = A3;
int IR5 = A4;

int IR1_Val;
int IR2_Val;
int IR3_Val;
int IR4_Val;
int IR5_Val;

void printPadded(int value, int width) {
  int digits = 1;
  for (int n = value; n >= 10; n /= 10) digits++;
  for (int i = digits; i < width; i++) Serial.print(' ');
  Serial.print(value);
  Serial.print(" ");
}

void setup() {
  Serial.begin(9600);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
}

void loop() {
  IR1_Val = analogRead(IR1);
  IR2_Val = analogRead(IR2);
  IR3_Val = analogRead(IR3);
  IR4_Val = analogRead(IR4);
  IR5_Val = analogRead(IR5);

  Serial.print("IR1: ");
  printPadded(IR1_Val, 4);
  Serial.print("IR2: ");
  printPadded(IR2_Val, 4);
  Serial.print("IR3: ");
  printPadded(IR3_Val, 4);
  Serial.print("IR4: ");
  printPadded(IR4_Val, 4);
  Serial.print("IR5: ");
  printPadded(IR5_Val, 4);
  
  Serial.println();
  delay(0);
}
/*

HERE IS THE PINOUT FOR THE ARDUINO, CHANGE TO WHAT YOU FEEL MORE COMPFORTABLE IF NEEDED.

right_2 = A4
right_1 = A3
Centre =  A2
Left_1  =  A1
Left_2  = A0

Use the digital sensor to test the weighted theory witht he PD control
if that works we can start moving onto how to intergrate the values from digital to ANALOGUE


*/
