
//DICHIARAZIONI GPS----------------------------------------------------------------------------------------------
#include <TinyGPS++.h>
TinyGPSPlus gps;

//DICHIARAZIONI SIM----------------------------------------------------------------------------------------------
#include <GSMSim.h>
#include <SoftwareSerial.h>

#define IS_IN_RUN_LIMIT_GPS 5.0
#define IS_IN_RUN_NUMBER_GPS 10

int N_GPS_value;

GSMSim gsm(12, 14);//RX, TX

//DICHIARAZIONI ACCELEROMETRO------------------------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>

#define IS_IN_RUN_LIMIT_ACC 1000//NUMERO DI CONFRONTO PER VALORE ACCELEROMETRO
#define IS_IN_RUN_NUMBER_ACC 500//NUMERO DI CONFRONTI MAGGIORI DI "IS_IN_RUN_LIMIT"

bool InRun_ACC;
int N_ACC_value;
long X, Y, Z, Acc;

Adafruit_MMA8451 mma = Adafruit_MMA8451();//INIZIALIZZA ACCELEROMETRO

//DICHIARAZIONI TIMER--------------------------------------------------------------------------------------------
#include <Ticker.h> 
Ticker Timer;

#define TIMER_TIME_MS 50//TEMPO TIMER

//DICHIARAZIONI OTA----------------------------------------------------------------------------------------------
#include <ArduinoOTA.h>
#include <FS.h> 
File fsUploadFile;

const char* HOME_ssid = "Vodafone-Menegatti";
const char* HOME_pass = "Menegatti13";

unsigned long thisTime, lastTime;

void setup() 
{
  GPS_Setup();
  SIM_Setup();
  OTA_Setup();
  MMA8451_Setup();

  Timer.attach_ms(TIMER_TIME_MS, Timer_interrupt);//INIZIALIZZA TIMER

  Serial1.println("Setup OK!");

}

void loop() 
{
  thisTime = millis();
  if(thisTime - lastTime > 1000 && InRun_ACC)//ROUTINE ESEGUITA OGNI 1000ms SENZA BLOCCARE IL CICLO E SE SIAMO IN RUN
  {
    if(IsInRun_GPS(gps.speed.kmph(), gps.speed.isValid()))
    {
      Notifica();
    }
    lastTime = millis();
  }

   //Serial1.print("\t"); Serial1.print(X); Serial1.print("\t"); Serial1.print(Y); Serial1.print("\t"); Serial1.println(Z);//STAMPA SU PLOTTER
}
