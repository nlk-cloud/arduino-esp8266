//Modbus Status
int MB_STS = 0;
bool MB_STS_JSON;

float Voltage_V1N;
float Voltage_V2N;
float Voltage_V3N;
float AVGVoltage_LN;

float Voltage_V12;
float Voltage_V23;
float Voltage_V31;
float AVGVoltage_LL;

float Current_I1;
float Current_I2;
float Current_I3;
float AVGCurrent;

float kW1;
float kW2;
float kW3;

float kVAr1;
float kVAr2;
float kVAr3;

float kVA1;
float kVA2;
float kVA3;

float Total_kW;
float Total_kVAr;
float Total_kVA;

float PF1;
float PF2;
float PF3;
float AVG_PF;

float Freq;


uint16_t MB_BF1[8]; // for reading line to neutral voltages and avg voltage
uint16_t MB_BF2[8]; // for reading voltage between lines and avg voltage
uint16_t MB_BF3[8]; // for reading currents of 3 phases and avrage current
uint16_t MB_BF4[6]; // for reading kw of 3 phases
uint16_t MB_BF5[6]; // for reading kvar of 3 phases
uint16_t MB_BF6[6]; // for reading kva of 3 phases
uint16_t MB_BF7[6]; // for reading total kw, kvar, kva of 3 phases
uint16_t MB_BF8[8]; // for reading power factor of 3 phases and average PF
uint16_t MB_BF9[2]; // for reading frequency 
