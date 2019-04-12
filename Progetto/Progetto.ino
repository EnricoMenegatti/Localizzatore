
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

long X, Y, Z, Acc;

Adafruit_MMA8451 mma = Adafruit_MMA8451();//INIZIALIZZA ACCELEROMETRO

void setup() 
{
  Serial.begin(115200);
  Serial.println("Setup...");

  OTA_Setup();
  MMA8451_Setup();

  Timer.attach_ms(50, Timer_interrupt);//INIZIALIZZA TIMER

  Serial.println("Setup OK!");
}

void loop() {
  Event_MMA8451();
  Serial.print(X); Serial.print("\t"); Serial.print(Y); Serial.print("\t"); Serial.println(Z);//STAMPA SU PLOTTER
}
