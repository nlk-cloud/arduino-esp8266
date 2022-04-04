//  This code works for SELEC EM4M meter + RS485 to TTL converter + ESP8266 ( WEMOS D1 R1 board ). The A+ on the meter is connected to A+ on the RS485 to ttl 
// board and B- to B-. The Vcc to RS485 is given from 3.3V of ESP board. THe D1 is connected D7 or GPIO13 on the ESP board and R0/ is connected to D6 or GPIO12
//The DE_RE pins are shorted and given to D2 on the ESP board . A termination resistor of 120ohm is connected both on the meter side as well as between A and B 
//of the RS485 to TTL board side. While reading the I register values using the mb.readIreg, give the address of the register as the address  given in manula +1 
// for ex. if frequency register in the manual is given as 30056, in the mb.readIreg address field put it as just 57.  

#include <ModbusRTU.h>
#include <ArduinoJson.h>
ModbusRTU mb;

#include <SoftwareSerial.h>
/*int DE_RE = 4; //D4  For MAX485 chip
int RX = 12; //R0 GPIO12
int TX = 13; // D1 GPIO13
*/

#define RX D6
#define TX D7
#define DE_RE D2


#include "IntToFloat.h"

SoftwareSerial S(RX, TX);//D6/D7  (RX , TX)

//uint16_t Mread0[24];
uint16_t Mread0[2];
//bool coils[20];
int i;

bool cbWrite(Modbus::ResultCode event, uint16_t transactionId, void* data) {
  Serial.printf_P("Request result: 0x%02X, Mem: %d\n", event, ESP.getFreeHeap());
  return true;
}

void setup() {
  Serial.begin(115200);
  S.begin(9600, SWSERIAL_8N1);
  mb.begin(&S, DE_RE); //Assing Software serial port to Modbus instance for MAX485 chip having DI,DE,RE,RO Pin at TTL side
  mb.master(); //Assing Modbus function as master
  Serial.println(); //Print empty line
  Serial.println(sizeof(Mread0)); //Reading size of first array
}
void loop() {
  if (!mb.slave()) {

   
    //for ex. if frequency register in the manual is given as 30056, in the mb.readIreg address field put it as just 57.  
    mb.readIreg(1, 1, Mread0, 2, cbWrite);  //(SlaevID,Address,Buffer,Range of data,Modus call)
    //mb.readCoil(1, 1, coils, 20, cbWrite);    
   
   //for(i=0; i<=23; i=i+2)
   {
   Serial.println(InttoFloat(Mread0[0], Mread0[1]));
   }


//mb.readHreg(1, 11, Mread0, 2, cbWrite);  //(SlaevID,Address,Buffer,Range of data,Modus call)    
//Serial.println(InttoFloat(Mread0[0], Mread0[1]));

  }
  mb.task();
  delay(2000);
  yield();
}