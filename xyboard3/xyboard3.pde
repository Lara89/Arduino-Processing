import processing.serial.*;
Serial port;

String data;

float val1 = 0;
float val2 = 0;
float val3 = 0;
float val4 = 0;
float val5 = 0;

float potenciometerX;
float potenciometerY;
float potenciometerZ;
float solarSensor;
float solarSensor2;

void setup() {
  size(displayWidth,displayHeight);
  port = new Serial(this, Serial.list()[5], 9600);
  port.bufferUntil('\n');
  background(255);
  rectMode(CENTER); 
}

void draw() {
  /*Split the data receive in the Serial Port, and add it to
  an array named list*/
  String values = data;
  String[] list = split(data, ',');  
  
  //Get the values from the array and separate them.
  float val1 = float(list[0]);
  float val2 = float(list[1]);
  float val3 = float(list[2]);
  float val4 = float(list[3]);
  float val5 = float(list[4]);
  
  //Rule of 3 to convert the values to de number needed
  potenciometerX = (val1 * width) / 1024;
  potenciometerY = (val2 * height) / 1024;
  potenciometerZ = (val3 * 255) / 1024;  
  solarSensor = (val4 * 400) / 900;
  solarSensor2 = (val5 * 400) / 900;

  
  /*Get one of the values of the potenciometers
  and make it something visible*/
  stroke(255);
  fill(potenciometerZ,potenciometerX,potenciometerY);
  rect(potenciometerX,potenciometerY,solarSensor,solarSensor2);
}


//Read the data from the serial port.
void serialEvent(Serial port) {
   data = port.readString();
}
