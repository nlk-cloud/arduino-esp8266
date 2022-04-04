char msg[2000];
void JSON_Pack() {
  const size_t capacity = 6 * JSON_OBJECT_SIZE(7) + JSON_OBJECT_SIZE(8);
  if (MB_STS == 228) MB_STS_JSON = 0;
  else MB_STS_JSON = 1;
  DynamicJsonDocument doc(capacity);
  doc["MB_STS"] = MB_STS_JSON;
  
  JsonObject Phase1 = doc.createNestedObject("Phase1");
  Phase1["Voltage1N"] = Voltage_V1N;
  Phase1["Voltage12"] = Voltage_V12;
  Phase1["Current1"] = Current_I1;
  Phase1["kw1"] = kW1;
  Phase1["kVAr1"] = kVAr1;
  Phase1["kVA1"] = kVA1;
  Phase1["PF1"] = PF1;


  JsonObject Phase2 = doc.createNestedObject("Phase2");
  Phase2["Voltage2N"] = Voltage_V2N;
  Phase2["Voltage23"] = Voltage_V23;
  Phase2["Current2"] = Current_I2;
  Phase2["kw2"] = kW2;
  Phase2["kVAr2"] = kVAr2;
  Phase2["kVA2"] = kVA2;
  Phase2["PF2"] = PF2;

  JsonObject Phase3 = doc.createNestedObject("Phase3");
  Phase3["Voltage3N"] = Voltage_V3N;
  Phase3["Voltage31"] = Voltage_V31;
  Phase3["Current3"] = Current_I3;
  Phase3["kw3"] = kW3;
  Phase3["kVAr3"] = kVAr3;
  Phase3["kVA3"] = kVA3;
  Phase3["PF3"] = PF3;


  JsonObject Average = doc.createNestedObject("Average");
  Average["AVGVoltage_LN"] = AVGVoltage_LN;
  Average["AVGVoltage_LL"] = AVGVoltage_LL;
  Average["AVGCurrent"] = AVGCurrent;
  Average["AVG_PF"] = AVG_PF;

  JsonObject Total = doc.createNestedObject("Total");
  Total["Total_kW"] = Total_kW;
  Total["Total_kVAr"] = Total_kVAr;
  Total["Total_kVA"] = Total_kVA;
  
  JsonObject Frequency = doc.createNestedObject("Frequency");
  Frequency["Freq"] = Freq;

  
  serializeJson(doc, Serial);
  serializeJson(doc, msg);
  Serial.println();
  client.publish("Selecem4m/Data/Json", msg);
  
  /*Gateway_Status = String(MB_STS_JSON);
  Inverter_Status = String(STATE);
  Inverter_Temp = String(TEMP);
  Energy_Today = String(ENR_TODAY_L);
  Energy_Total = String(ENR_TOT_L);
  Panel_Volatge = String(PV_VLT);
  Panel_Amps = String(PV_AMP);
  Panel_Power = String(PV_WATT_L);
  Fault = String(FAUTL);
  Warning = String(WARNING);
*/

}