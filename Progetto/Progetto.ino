
//DICHIARAZIONI GPS----------------------------------------------------------------------------------------------
#include <TinyGPS++.h>
TinyGPSPlus gps;

float temp;
//DICHIARAZIONI SIM----------------------------------------------------------------------------------------------
#include "Adafruit_FONA.h"
#include <GSMSim.h>
#include <SoftwareSerial.h>

#define IS_IN_RUN_LIMIT_GPS 5.0
#define IS_IN_RUN_NUMBER_GPS 10

int N_GPS_value;
uint8_t type;
char imei[16] = {0}; // Use this for device ID

//GSMSim gsm(12, 14);//RX, TX
SoftwareSerial gsm = SoftwareSerial(12, 14, false, 256); // RX, TX, inverted logic, buffer size
SoftwareSerial *gsmSerial = &gsm;

Adafruit_FONA fona = Adafruit_FONA(0);

//DICHIARAZIONI ACCELEROMETRO------------------------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>

#define IS_IN_RUN_LIMIT_ACC 550//NUMERO DI CONFRONTO PER VALORE ACCELEROMETRO
#define IS_IN_RUN_NUMBER_ACC 5//NUMERO DI VIBRAZIONE IN UN SECONDO
#define LAST_ACC_OFFSET 50//DIFFERENZA MASSIMA TRA VALORE ATTUALE E PRECEDENTE

bool InRun_ACC;
int N_ACC_value;
long X, Y, Z, Acc, Last_Acc;

Adafruit_MMA8451 mma = Adafruit_MMA8451();//INIZIALIZZA ACCELEROMETRO

//DICHIARAZIONI TIMER--------------------------------------------------------------------------------------------
#include <Ticker.h> 
Ticker Timer_Acc;
Ticker Timer_gps;
Ticker Timer_1;
Ticker Timer_gsm;

#define TIMER_ACC_MS 50//TEMPO TIMER ACCELEROMETRO
#define TIMER_GPS_MS 1000//TEMPO TIMER GPS

long Timer_cont;

//DICHIARAZIONI OTA----------------------------------------------------------------------------------------------
#include <ArduinoOTA.h>
#include <FS.h> 
File fsUploadFile;

const char* HOME_ssid = "Vodafone-Menegatti";
const char* HOME_pass = "Menegatti13";
const char* HOST_name = "ESP_GPS-Tracker";

void setup() 
{
  GPS_Setup();
  //SIM_Setup();
  OTA_Setup();
  MMA8451_Setup();

  Timer_Acc.attach_ms(TIMER_ACC_MS, Timer_Acc_interrupt);//INIZIALIZZA TIMER
  Timer_gps.attach_ms(TIMER_GPS_MS, Timer_gps_interrupt);//INIZIALIZZA TIMER
  Timer_1.attach_ms(1000, Timer_1_interrupt);//INIZIALIZZA TIMER
  //Timer_gsm.attach_ms(2000, Timer_gsm_interrupt);//INIZIALIZZA TIMER

  Serial1.println("Setup OK!");

}

void loop() 
{  
  while (Serial.available() > 0)//LETTURA DATI GPS
    gps.encode(Serial.read());

  ArduinoOTA.handle();
   //Serial1.print("\t"); Serial1.print(X); Serial1.print("\t"); Serial1.print(Y); Serial1.print("\t"); Serial1.println(Z);//STAMPA SU PLOTTER
}
