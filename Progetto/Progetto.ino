
//LIBRERIE GPS----------------------------------------------------------------------------------------------
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
TinyGPSPlus gps;

SoftwareSerial MySerial(12, 13);//RX, TX

//LIBRERIE SIM----------------------------------------------------------------------------------------------
#include <GSMSim.h>

GSMSim gsm(4, 3);//RX, TX

//LIBRERIE ACCELEROMETRO------------------------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>

String tempSerial, tempGSM;

unsigned long thisTime, lastTime; 

long X, Y, Z, Acc;

Adafruit_MMA8451 mma = Adafruit_MMA8451();//INIZIALIZZA ACCELEROMETRO

void setup() 
{
  Serial.begin(9600);
  Serial.println("Setup...");

  GPS_Setup();
  SIM_Setup();
  MMA8451_Setup();

  Serial.println("Setup OK!");
}

void loop() 
{
  thisTime = millis();
  if(thisTime - lastTime > 1000)
  {
    Dati_GPS();
    lastTime = millis();
  }
  
  Event_MMA8451();
  Dati_SIM();
  //Serial.print("\t"); Serial.print(X); Serial.print("\t"); Serial.print(Y); Serial.print("\t"); Serial.println(Z);//STAMPA SU PLOTTER
}
