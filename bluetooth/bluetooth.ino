#include <SoftwareSerial.h>

int bluetoothTx = 2;
int bluetoothRx = 3;
int led = 12;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and turn on an LED
  if(bluetooth.available())
  {
    int toDo = (int)bluetooth.read();
    if(toDo == 1)
    {
      digitalWrite(12,HIGH);
    }
    
    else
    {
      digitalWrite(12,LOW);
    }
  }

  delay(100);
}
