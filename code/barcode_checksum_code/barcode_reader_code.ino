//JUST barcode reading NOT decoding yet
#include <Arduino.h>

//variables
const int sensor_pin = A0;

//sensor threshold between black (<threshold) and white (>threshold)
int threshold = 500;

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
}

void loop() {
  // put your main code here, to run repeatedly:
  get_colour();
}

bool get_colour(){
  int value = analogRead(sensor_pin);
  //determine current bar colour based off sensor reading
  if (value<threshold){
    return true; //black
  }
  else {
    return false; //white
  }
}

void colour_change(){
  current_colour = get_colour();
  //if quiet zone then time starts at start of guard bar
  if (quiet_zone) {
    //start of guard bar = colour changes from white to black
    if (current_colour != previous_colour){
      //record time of change
      previous_time = micros();
      quiet_zone = false;
    }
  }
  //if not quite zone then each change is end of previous bar
  else {
    if (current_colour != previous_colour){
      //record time of change
      current_time = micros();
    }
  }
  //update previous colour for next detection
  previous_colour = current_colour;
}

void read_barcode(){
    //first colour change is start of guard bar so record time
    colour_change();
}