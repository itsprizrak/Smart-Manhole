#include<SoftwareSerial.h>
SoftwareSerial gsm(10, 11);

//Pin configuration
int x = A0;                        //For X axis in accelerometer
int gas = A1;                      //Fire detector
int water = A2;                    //Flood detector

//Initialize the Threshold
int x_Threshold = 300;
int gas_Threshold = 525 ;
int overflow_Threshold = 225;

void setup()
{
  gsm.begin(9600);
  pinMode(x , INPUT);
  pinMode(water , INPUT);
  pinMode(gas , INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Code for Landslide detection
  int valx = analogRead(x);
  Serial.println(valx);
  delay(400);
  if (valx <= x_Threshold) {
    gsm.println("AT+CMGF=1");
    delay(100);
    gsm.println("AT+CMGS=\"+917338115820\"\r"); //replace x by your number
    delay(100);
    gsm.println("Manhole Coverage Tilted");
    delay(100);
    gsm.println((char)26);
    delay(100);
  }

  //Code for Gas Detection
  int gasval = analogRead(gas);
  Serial.println(gasval);
  delay(400);
  if (gasval >= gas_Threshold) {
    gsm.println("AT+CMGF=1");
    delay(100);
    gsm.println("AT+CMGS=\"+917338115820\"\r"); //replace x by your number
    delay(100);
    gsm.println("High level of Gas");
    delay(100);
    gsm.println((char)26);
    delay(100);
  }

  //Code for Overflow detection
  int waterval = analogRead(water);
  Serial.println(waterval);
  delay(400);
  if (waterval <= overflow_Threshold) {
    gsm.println("AT+CMGF=1");
    delay(100);
    gsm.println("AT+CMGS=\"+917338115820\"\r"); //replace x by your number
    delay(100);
    gsm.println("Water level High");
    delay(100);
    gsm.println((char)26);
    delay(100);
  }
}
