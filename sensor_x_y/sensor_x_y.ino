//Code by Andres Lara
/*Note: This code allows the user to get data from different
electronic elements such as button, potenciometers and solar sensor,
and send the data in a string to the serial port. This data
can be use in processing to create different elements.*/

//Pin Numbers
int potenciometerXPin = A0;
int potenciometerYPin = A1;
int potenciometerZPin = A2;
int solarSensorPin = A3;
int solarSensorPin2 = A4;
int buttonStatePin = 11;
int counterNumber = 0;
int maxCounter = 4;

int potenciometerX;
int potenciometerY;
int potenciometerZ;
int solarSensor;
int solarSensor2;
int buttonState;
String strVal1;
String strVal2;
String strVal3;
String strVal4;
String strVal5;

void setup(){               
  pinMode(potenciometerXPin, INPUT);
  pinMode(potenciometerYPin, INPUT);
  pinMode(potenciometerZPin, INPUT);
  pinMode(solarSensorPin, INPUT);
  pinMode(solarSensorPin2, INPUT);
  pinMode(buttonStatePin, INPUT);
  Serial.begin(9600);
}

void loop(){
  //Reads the information from each port.
  potenciometerX = analogRead(potenciometerXPin);
  potenciometerY = analogRead(potenciometerYPin);
  potenciometerZ = analogRead(potenciometerZPin);
  solarSensor = analogRead(solarSensorPin);
  solarSensor2 = analogRead(solarSensorPin2);
  //buttonState = digitalRead(buttonStatePin);  
  
  //Converts every element to a string
  strVal1 = String(potenciometerX);
  strVal2 = String(potenciometerY);
  strVal3 = String(potenciometerZ);  
  strVal4 = String(solarSensor);
  strVal5 = String(solarSensor2);

  //If button is clicked this will add one digit to counter
  /*if (buttonState == HIGH) {     
      counterNumber++;
      delay(1000);
  }*/
  
  //This allow to have a max limit to the counter
  /*if (counterNumber >= maxCounter) {
     counterNumber = 0; 
  }*/
  
  //Send all the strings into a same line separeted by coma.
  Serial.println(strVal1 + "," + strVal2 + "," + strVal3 + "," + strVal4 + "," + strVal5);
  
}
