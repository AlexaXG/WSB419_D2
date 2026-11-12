//JUST barcode reading NOT decoding yet
#include <Arduino.h>

//variables
const int sensor_pin = A2;

//sensor threshold between black (<threshold) and white (>threshold)
//TEST SENSOR IS DIGITAL SO NOT NEEDED
//int threshold = 500;

//variable for storing time periods in duration array
int bar_count = 0;

//initially colour is white
bool current_colour = false;
bool previous_colour = false;

//detect quiet zone
bool quiet_zone = true;

//time variables
unsigned long previous_time = 0;
unsigned long current_time = 0;
unsigned long duration[67];

//define functions

bool get_colour();

void read_barcode();

void colour_change();

void setup() {
  Serial.begin(9600);

  pinMode(sensor_pin, INPUT);

  previous_colour = get_colour();
}

void loop() {
  // put your main code here, to run repeatedly:
  read_barcode();
}

bool get_colour(){
  int value = analogRead(sensor_pin);

  //determine current bar colour based off sensor reading
  //CHANGE TO DIGITAL READ FOR TEST SENSOR
  //if (value<threshold){
  if (value==LOW){

    return true; //black
  }
  else {
    return false; //white
  }
}

void colour_change(){
  current_colour = get_colour();

  //detect colour transition
  if (current_colour != previous_colour){

    //time of transition
    current_time = micros();

    //if quiet zone
    if (quiet_zone){
      
      //start of guard bar = colour changes from white to black
      if (previous_colour == false && current_colour == true){

        //record time at beginning of guard bar
        previous_time = current_time;

        //end of quiet zone
        quiet_zone = false;

        Serial.println("Start of barcode detected!");

      }
      //end of guard bar code:
    }
    else {
      //calculate time period and store in array
      unsigned long time_period = current_time - previous_time;

      //store if array is not full
      if (bar_count < 67){
        duration[bar_count] = time_period;

        Serial.print("Duration ");
        Serial.print(bar_count);
        Serial.print(": ");
        Serial.println(duration[bar_count]);

        bar_count++;
      }
      else {
        Serial.println("Array full!");
      }   
      //update previous time for next detection
      previous_time = current_time;
    }
  }
  //update previous colour for next detection
  previous_colour = current_colour;
}

void read_barcode(){
    //first colour change is start of guard bar so record time
    colour_change();
}