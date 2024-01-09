#include<SoftwareSerial.h>

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial BT(12 , 14); /* (Rx,Tx) */  

int led = 13;
String readdata;

void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
  Serial.println("Bluetooth Started! Ready to pair...");
  pinMode(led, OUTPUT);
}

void loop() {
  
  while (BT.available())
  {
    delay(10);
    char c = BT.read();
    readdata += c;
  }
  
  if (readdata.length() > 0)
  {
    Serial.print("data=");
    Serial.print(readdata);
    Serial.println("");
    
    if (readdata == "led on") {
      digitalWrite(led, HIGH);
      BT.println("  led on");
    }

    if (readdata == "led off") {
      digitalWrite(led, LOW);
      BT.println("  led off");
    }
    readdata = "";
  }
}
