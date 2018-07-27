#include <nmea.h>  
#include <SoftwareSerial.h>

NMEA nmeaDecoder(ALL);  

char incomingByte;
SoftwareSerial nmeaSerial(8,9); // RX pin, TX pin (not used), and true means we invert the signal 

void setup(){
  Serial.begin(38400);  
  nmeaSerial.begin(38400);  
  delay(500);
  Serial.begin(9600);  // USB, communication to PC or Mac
  delay(500);
}

void loop(){

  //incomingByte = Serial.read();    // read incoming
  //Serial.print(incomingByte);  // send incoming
  //incomingByte = nmeaSerial.read();    // read incoming
  //Serial.print(incomingByte);
 if (nmeaSerial.available()) {  
   if (nmeaDecoder.decode(nmeaSerial.read())) {  // if we get a valid NMEA sentence  
     Serial.println(nmeaDecoder.sentence()); 
    
     char *t = nmeaDecoder.term(0);
     Serial.print("Sentence: ");
     Serial.println(t);
     if( t[4] == 'C')
     {  
        char* t0 = nmeaDecoder.term(3);
        char* t1 = nmeaDecoder.term(5);
        Serial.print("Latitude: ");
        Serial.println(t0);
        Serial.print("Longitude: ");
        Serial.println(t1);
      } 
     }  
   }  
 
}
