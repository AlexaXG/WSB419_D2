
int centreA = A2;
int centreD = 2;

int centreValA;
int centreValD;

void setup() {
  Serial.begin(9600);

  pinMode(centreD, INPUT);
}

void loop() {

  centreValA = analogRead(centreA);
  centreValD = digitalRead(centreD);

  Serial.print("Analogue reading: ");
  Serial.print(centreValA);

  Serial.print(" | Digital reading: ");
  Serial.println(centreValD);

  delay(700);
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
