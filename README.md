# Arduino and Garmin GPS 19x
### Hardware components:
* Ultra Compact RS232 to TTL Converter with Male DB9 (3.3V to 5V)  [buy!](https://www.amazon.com/gp/product/B00OPU2QJ4/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1)
* Garmin GPS 19x HVS (NMEA 0183) [buy!](https://buy.garmin.com/en-US/US/p/100686#specs)
* Arduino Uno
* 12v power source
### Connection:
![Connection](https://github.com/Yang-Yanxiang/Arduino-Garmin-GPS-19x/blob/master/connection.png)
![Gmarmin GPS pinout](https://github.com/Yang-Yanxiang/Arduino-Garmin-GPS-19x/blob/master/pinout.png)
### Example code:
```
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
   if (nmeaSerial.available()) {  
     if (nmeaDecoder.decode(nmeaSerial.read())) {  // if we get a valid NMEA sentence  
       Serial.println(nmeaDecoder.sentence()); 

       char *t = nmeaDecoder.term(0);
       Serial.print("Sentence: ");
       Serial.println(t);
       if( t[4] == 'C') {  
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
```
