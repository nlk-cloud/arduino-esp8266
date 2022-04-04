uint16_t CALL_STP = 0;
unsigned long Post_window = 0;
void ModbusCall() {
  if (CALL_STP == 0) {
    if (!mb.slave()) {
         mb.readIreg(1, 1, MB_BF1, 8, cbWrite);  //(SlaevID,Address,Buffer,Range of data,Modus call)
      for (uint16_t x = 0; x < 8 ; x++) {
      }
      CALL_STP = 1;
      //ArduinoOTA.handle();
    }
    
    Voltage_V1N=InttoFloat(MB_BF1[0], MB_BF1[1]);
    Voltage_V2N=InttoFloat(MB_BF1[2], MB_BF1[3]);
    Voltage_V3N=InttoFloat(MB_BF1[4], MB_BF1[5]);
    AVGVoltage_LN=InttoFloat(MB_BF1[6], MB_BF1[7]);

  }

  if (CALL_STP == 1) {
    if (!mb.slave()) {
      mb.readIreg(1, 9, MB_BF2, 8, cbWrite); //(SlaevID,Address,Buffer,Range of data,Modus call)
      for (uint16_t x = 0; x < 8; x++) {
      }
      CALL_STP = 2;
      //ArduinoOTA.handle();
    }

    Voltage_V12=InttoFloat(MB_BF2[0], MB_BF2[1]);
    Voltage_V23=InttoFloat(MB_BF2[2], MB_BF2[3]);
    Voltage_V31=InttoFloat(MB_BF2[4], MB_BF2[5]);
    AVGVoltage_LL=InttoFloat(MB_BF2[6], MB_BF2[7]);

   }

  if (CALL_STP == 2) {
    if (!mb.slave()) {
      mb.readIreg(1, 17, MB_BF3, 8, cbWrite); //(SlaevID,Address,Buffer,Range of data,Modus call)
      for (uint16_t x = 0; x < 8; x++) {
      }
      CALL_STP = 3;
     // ArduinoOTA.handle();
    }

    Current_I1=InttoFloat(MB_BF3[0], MB_BF3[1]);
    Current_I2=InttoFloat(MB_BF3[2], MB_BF3[3]);
    Current_I3=InttoFloat(MB_BF3[4], MB_BF3[5]);
    AVGCurrent=InttoFloat(MB_BF3[6], MB_BF3[7]);

  }
  if (CALL_STP == 3) {
    if (!mb.slave()) {
      mb.readIreg(1, 25, MB_BF4, 6, cbWrite); //(SlaevID,Address,Buffer,Range of data,Modus call)
      for (uint16_t x = 0; x < 6; x++) {
      }
      CALL_STP = 4;
      //ArduinoOTA.handle();
    }

    kW1=InttoFloat(MB_BF4[0], MB_BF4[1]);
    kW2=InttoFloat(MB_BF4[2], MB_BF4[3]);
    kW3=InttoFloat(MB_BF4[4], MB_BF4[5]);

  }
  if (CALL_STP == 4) {
    if (!mb.slave()) {
      mb.readIreg(1, 31, MB_BF5, 6, cbWrite); //(SlaevID,Address,Buffer,Range of data,Modus call)
      for (uint16_t x = 0; x < 6; x++) {
      }
      CALL_STP = 5;
      //ArduinoOTA.handle();
    }

    kVAr1=InttoFloat(MB_BF5[0], MB_BF5[1]);
    kVAr2=InttoFloat(MB_BF5[2], MB_BF5[3]);
    kVAr3=InttoFloat(MB_BF5[4], MB_BF5[5]);

  }
  if (CALL_STP == 5) {
    if (!mb.slave()) {
      mb.readIreg(1, 37, MB_BF6, 6, cbWrite);
      for (uint16_t x = 0; x < 6; x++) {
      }
      CALL_STP = 6;
      //ArduinoOTA.handle();
    }
    
    kVA1=InttoFloat(MB_BF6[0], MB_BF6[1]);
    kVA2=InttoFloat(MB_BF6[2], MB_BF6[3]);
    kVA3=InttoFloat(MB_BF6[4], MB_BF6[5]);
    
    }

  if (CALL_STP == 6) {
    if (!mb.slave()) {
      mb.readIreg(1, 43, MB_BF7, 6, cbWrite);
      //Serial.print("Seventh:-");
      for (uint16_t x = 0; x < 6; x++) {
      }
      CALL_STP = 7;
      //ArduinoOTA.handle();
    }
    
    Total_kW=InttoFloat(MB_BF7[0], MB_BF7[1]);
    Total_kVAr=InttoFloat(MB_BF7[2], MB_BF7[3]);
    Total_kVA=InttoFloat(MB_BF7[4], MB_BF7[5]);
    
    }

 if (CALL_STP == 7) {
    if (!mb.slave()) {
      mb.readIreg(1, 49, MB_BF8, 8, cbWrite);
      //Serial.print("Seventh:-");
      for (uint16_t x = 0; x < 8; x++) {
      }
      CALL_STP = 8;
      //ArduinoOTA.handle();
    }
    
    PF1=InttoFloat(MB_BF8[0], MB_BF8[1]);
    PF2=InttoFloat(MB_BF8[2], MB_BF8[3]);
    PF3=InttoFloat(MB_BF8[4], MB_BF8[5]);
    AVG_PF=InttoFloat(MB_BF8[6], MB_BF8[7]);
    }

if (CALL_STP == 8) {
    if (!mb.slave()) {
      mb.readIreg(1, 57, MB_BF9, 2, cbWrite);
      //Serial.print("Seventh:-");
      for (uint16_t x = 0; x < 1; x++) {
      }
      CALL_STP = 0;
      //ArduinoOTA.handle();
    }
    
    Freq=InttoFloat(MB_BF9[0], MB_BF9[1]);
    }

  if (millis() - Post_window > Window_Time) {
    JSON_Pack();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(200);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(200);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(200);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    Post_window += Window_Time;
    //ArduinoOTA.handle();
  }
}