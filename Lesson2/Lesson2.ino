/*
Programmer: Sage Smith
Tutorial 2: Serial turn on and off Led
Wiring: *OPTION 1* tall end of LED in port 13, short end in GND. This works because port 13 has a built in resistor
        *OPTION 2* Wire out of port 12 (positive) to breadboard then resistor (100 oms) then tall end of led then wire from bread board to GND (negative)
*/

//LED we will be using
int pin = 13;
int baudRate = 9600;
char incomingInfo;
char on = '1', off = '2';

//setup runs once on startup of arduino
void setup(){
  //this method designates whether a specified pin will be listening to input or sending output
  //in this example we will be sending output to our designated pin
  pinMode(pin, OUTPUT);
  
  // Serial.begin(int) tells the arduino to listen to Serial input. The BaudRate is how many times per second a signal changes (or could change).
 // In order to communicate with the computer and the arduino their baudRates must be the same
  Serial.begin(baudRate);
}

//this loop runs continuously while arduino is on, exactly the same as a while(true){} in java
void loop(){
  //Checks to see if the computer has sent any information
  if(Serial.available()){
    //This line typcasts the information that is read from a byte to a char
    incomingInfo = (char) Serial.read(); 
    
    //checks to see if we told it to be turned on
    if(incomingInfo == on){
      //digitalWrite(int, int) is used to turn on pin switch HIGH turns switch on LOW turns switch off
      digitalWrite(pin, HIGH);
    }
    
    //checks to see if we told it to turn off
    else if(incomingInfo == off){
      digitalWrite(pin, LOW);
    }
    
    //Tells the computer what the arduino Recieved
    Serial.println(incomingInfo);
    
    //delay(long) delays the loop by the specified number of milliseconds exactly like a Thread.sleep(long) in java
    delay(50);
  }
  //To communicate with arduino go to tools->Serial Monitor->and type what you would like to send in the textbox and hit send or enter
}
