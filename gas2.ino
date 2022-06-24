#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(9, 10); //RX, TX

int buzzer = 5; //buzzer to arduino pin 9
int gasValue = A0; // smoke / gas sensor connected with analog pin A1 of the arduino / mega.
int data = 0;

void setup()
{
  randomSeed(analogRead(0));
  gsmSerial.begin(9600); // Setting the baud rate of GSM Module
  Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
  pinMode(gasValue, INPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  delay(3000);
}

void loop()
{

  data = analogRead(gasValue);
  delay(500);
  Serial.println(data);

  if ( data > 200) 
  {
    SendMessage();
    tone(buzzer, 100); // Sends sound signal...
    delay(5000);
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
  }
  else noTone(buzzer);     // Stop sound...
}

void SendMessage()
{
   gsmSerial.println("AT+CMGF=1\r");
   delay(500);
     
   Serial.println("Sending SMS to the desired phone number!");
   gsmSerial.println("AT+CMGS=\"+919748123480\"\r"); // Replace x with mobile number
   delay(500);

   gsmSerial.println("Excess Smoke/Gas Detected. Open the Window. \n\nIGNORE IF FALSE POSITIVE, Incoming messages will stop after the threshold value goes down.");    // SMS Text
   delay(100);

   
   /*
   gsmSerial.println("AT+CMGS=\"+918584027157\"\r"); // Replace x with mobile number
   delay(2000);
   gsmSerial.println("Possible Fire Outbreak Detected at **ADDRESS** ");    // SMS Text
   delay(200);
   */
   
   


   
   /*gsmSerial.print("https://www.google.com/maps/?q=");
   gsmSerial.print(gpslat, 6);
   gsmSerial.print(",");
   gsmSerial.print(gpslon, 6);
   gsmSerial.print("\n\nLatitude : ");
   gsmSerial.println(gpslat, 6);
    Serial.println(gpslat);
   gsmSerial.print("Longitude : ");
   gsmSerial.println(gpslon, 6);
   Serial.println(gpslon);
   gsmSerial.write(0x1A);
   delay(100);  */

         gsmSerial.println((char)26);               // ASCII code of CTRL+Z
         delay(500);
    
 }
 
