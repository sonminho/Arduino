#include "Bluetooth.h"

 Bluetooth BTSerial(2,3,9600);
 
void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  String message = BTSerial.readLine();
  
  if(message != NULL) {
    if(message == "on") {
      digitalWrite(13, HIGH);
      BTSerial.println("LED ON");
    }
    else if(message == "off") {
      digitalWrite(13, LOW);
      BTSerial.println("LED OFF");
    }
    Serial.println(message);
  }
}
