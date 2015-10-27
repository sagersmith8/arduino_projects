/*
Programmer: Sage Smith
Tutorial 1: Turn on and off Led
Wiring: *OPTION 1* tall end of LED in port 13, short end in GND. This works because port 13 has a built in resistor
        *OPTION 2* Wire out of port 12 (positive) to breadboard then resistor (100 oms) then tall end of led then wire from bread board to GND (negative)
*/

//LED we will be using
int pin = 13, pin2 = 12;

//setup runs once on startup of arduino
void setup(){
  //this method designates whether a specified pin will be listening to input or sending output
  //in this example we will be sending output to our designated pin
  pinMode(pin, OUTPUT);
  pinMode(pin2,OUTPUT);
}

//this loop runs continuously while arduino is on, exactly the same as a while(true){} in java
void loop(){
  //digitalWrite(int, int) is used to turn on pin switch HIGH turns switch on LOW turns switch off
  digitalWrite(pin, HIGH);
  //delay(long) delays the loop by the specified number of milliseconds exactly like a Thread.sleep(long) in java
  delay(500);
  digitalWrite(pin, LOW);
  digitalWrite(pin2,HIGH);
  delay(500);
  digitalWrite(pin2,LOW);
}
