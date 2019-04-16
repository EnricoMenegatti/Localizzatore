
//LIBRERIE GPS----------------------------------------------------------------------------------------------
#include <TinyGPS++.h>
TinyGPSPlus gps;

//LIBRERIE SIM----------------------------------------------------------------------------------------------
#include <GSMSim.h>
#include <SoftwareSerial.h>

GSMSim gsm(12, 14);//RX, TX

//LIBRERIE ACCELEROMETRO------------------------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>

//LIBRERIE TIMER--------------------------------------------------------------------------------------------
#include <Ticker.h> 
Ticker Timer;

//LIBRERIE OTA----------------------------------------------------------------------------------------------
#include <ArduinoOTA.h>
#include <FS.h> 
File fsUploadFile;

const char* HOME_ssid = "Vodafone-Menegatti";
const char* HOME_pass = "Menegatti13";

unsigned long thisTime, lastTime;
long X, Y, Z, Acc;

Adafruit_MMA8451 mma = Adafruit_MMA8451();//INIZIALIZZA ACCELEROMETRO

void setup() 
{
  GPS_Setup();
  SIM_Setup();
  OTA_Setup();
  MMA8451_Setup();

  Timer.attach_ms(50, Timer_interrupt);//INIZIALIZZA TIMER

  Serial1.println("Setup OK!");

}

void loop() 
{
  thisTime = millis();
  if(thisTime - lastTime > 1000)//ROUTINE ESEGUITA OGNI 1000ms SENZA BLOCCARE IL CICLO
  {
    Dati_GPS();
    lastTime = millis();
  }

  Event_MMA8451();
  Dati_GPS();

   //Serial1.print("\t"); Serial1.print(X); Serial1.print("\t"); Serial1.print(Y); Serial1.print("\t"); Serial1.println(Z);//STAMPA SU PLOTTER
}
