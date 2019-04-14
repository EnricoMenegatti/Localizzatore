
//LIBRERIE GPS----------------------------------------------------------------------------------------------
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
TinyGPSPlus gps;

SoftwareSerial MySerial(12, 14);//RX, TX

//LIBRERIE SIM----------------------------------------------------------------------------------------------
#include <GSMSim.h>

#define RX 0
#define TX 2
#define RESET 3
#define BAUD 9600

GSMSim gsm(RX, TX, RESET);

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

String tempSerial, tempGSM;

const char* HOME_ssid = "Vodafone-Menegatti";
const char* HOME_pass = "Menegatti13";

long X, Y, Z, Acc;

Adafruit_MMA8451 mma = Adafruit_MMA8451();//INIZIALIZZA ACCELEROMETRO

void setup() 
{
  Serial.begin(115200);
  Serial.println("Setup...");

  GPS_Setup();
  SIM_Setup();
  OTA_Setup();
  MMA8451_Setup();

  Timer.attach_ms(50, Timer_interrupt);//INIZIALIZZA TIMER

  Serial.println("Setup OK!");

  //sim.sendSms("+393382606078","prova");
}

void loop() {
  Event_MMA8451();
  dati_GPS();
   //Serial.print("\t"); Serial.print(X); Serial.print("\t"); Serial.print(Y); Serial.print("\t"); Serial.println(Z);//STAMPA SU PLOTTER
}
