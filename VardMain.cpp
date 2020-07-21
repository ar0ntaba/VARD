const int x=A3;

const int y=A4;

const int z=A5;

int xsample=0;

int ysample=0;

int zsample=0;

#include <SoftwareSerial.h>

#include <hcrs04.h>

float latitude=0;

float logitude=0;   

int i=0;

#define count_max 25

#define PINTRIG 11

#define PINECHO 12

const int buzzer = 9;

const int ledPin = 2;

hcrs04 mySensor(PINTRIG, PINECHO);

#define samples 10

#define minVal -1

#define MaxVal 1

SoftwareSerial sGSM(14, 15);

void setup()

{

   pinMode(ledPin, OUTPUT);

  noTone(buzzer);     // Stop sound...

   mySensor.begin(); /* Initialize the sensor */

 

  Serial.begin(9600);

  sGSM.begin(9600);     

  delay(1000);

  Serial.println("successfully Initialized....");

  for(int i=0;i<samples;i++)

  {

    xsample+=analogRead(x);

    ysample+=analogRead(y);

    zsample+=analogRead(z);

  }

 

  xsample/=samples;

  ysample/=samples;

  zsample/=samples;

 

  Serial.println(xsample);

  Serial.println(ysample);

  Serial.println(zsample);

  delay(2000);

}

 

void Send()

{

 

    Serial.println("Accident Happened");

   delay(500);

   Serial.println("Click On link to see Location");

   Serial.print("http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=");

   Serial.print(latitude,6);

   Serial.print("+");            

   Serial.println(logitude,6);

   Serial.write(26);  

    sGSM.print("\r");

    delay(1000);

    sGSM.print("AT+CMGF=1\r");

    delay(1000);

    sGSM.print("AT+CMGS=\"+639476801003\"\r");

    delay(1000);

    //The text of the message to be sent.

    

}

void Sends()

{

sGSM.println("Accident Happened");

     delay(500);

    sGSM.println("Click On link to see Location");

    sGSM.print("http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=");

    sGSM.print(latitude,6);

    sGSM.print("+");            

    sGSM.println(logitude,6);

    sGSM.write(26);

   

}

 void alarm()

     

{

 

     digitalWrite(ledPin, LOW); 

  noTone(buzzer);     // Stop sound...

  delay(500);        // ...for 1sec

digitalWrite(ledPin, HIGH);

 tone(buzzer, 1000); // Send 1KHz sound signal...          

delay(500);

      digitalWrite(ledPin, LOW); 

  noTone(buzzer);     // Stop sound...

  delay(500);        // ...for 1sec

}

 void alarms()

     

{

 

     digitalWrite(ledPin, LOW); 

  noTone(buzzer);     // Stop sound...

  delay(500);        // ...for 1sec

digitalWrite(ledPin, HIGH);

 tone(buzzer, 1000); // Send 1KHz sound signal...          

delay(2000

...