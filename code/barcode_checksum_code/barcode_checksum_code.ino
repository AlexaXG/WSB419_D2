#include <Arduino.h>

//CONSTANTS

//test array for checksum function
int my_array[8] = {1,2,3,4,5,6,7,0};

int checkdigit = my_array[7];

//define functions
void calculate_checksum();

void setup() {
  Serial.begin(9600);
}

void loop() {
  calculate_checksum();
}

void calculate_checksum(){
  int sum = 0;
  int calculated_checkdigit;
  Serial.println("calculating checksum:");
  delay(1000);
  //sum the number with correct weightings
  for (int i=0; i<7; i++){
    //odd number indexes (2nd 4th etc numbers) have a weighting of 1
    if (i%2==1){
      if (i==0){
        Serial.print("0");
        Serial.print("+");
        Serial.print(my_array[i]);
        Serial.print("=");
        sum += my_array[i];
        Serial.println(sum);    }
      else {
        Serial.print(sum);
        Serial.print("+");
        Serial.print(my_array[i]);
        Serial.print("=");
        sum += my_array[i];
        Serial.println(sum);
      }
    }
    //even number indexes (1st, 3rd etc numbers) have a weighting of 3
    else {
      Serial.print(sum);
      sum += my_array[i]*3;
      Serial.print("+");
      Serial.print(my_array[i]);
      Serial.print("*3=");
      Serial.println(sum);
    }
    delay(1000);
  }

  if (sum%10==0){
    calculated_checkdigit = 0;
  }
  else {
  calculated_checkdigit = 10-(sum%10);
  }
  Serial.print("calculated checkdigit is: ");
  Serial.println(calculated_checkdigit);
  delay(1000);
  if (calculated_checkdigit==checkdigit){
    Serial.println("calculated checkdigit correctly");
  }
  else {
    Serial.println("calculated checkdigit incorrectly");
  }
  delay(1000);
}
