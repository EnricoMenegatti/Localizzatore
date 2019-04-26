
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

//DICHIARAZIONI WI-FI--------------------------------------------------------------------------------------------
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

const char* WIFI_ssid = "WIFI_GPS-Tracker";
const char* WIFI_pass = "Menegatti13";

IPAddress IP(192,168,4,1);
IPAddress GTW(192,168,4,1);
IPAddress mask = (255, 255, 255, 0);

ESP8266WebServer server(80);
WebSocketsServer webSocket(81);

int modalita;

void setup() 
{
  GPS_Setup();
  OTA_Setup();
  //WIFI_Setup();
  SPIFFS_Setup();
  //SIM_Setup();
  MMA8451_Setup();

  Timer_Acc.attach_ms(TIMER_ACC_MS, Timer_Acc_interrupt);//INIZIALIZZA TIMER
  Timer_gps.attach_ms(TIMER_GPS_MS, Timer_gps_interrupt);//INIZIALIZZA TIMER
  Timer_1.attach_ms(1000, Timer_1_interrupt);//INIZIALIZZA TIMER
  //Timer_gsm.attach_ms(2000, Timer_gsm_interrupt);//INIZIALIZZA TIMER

  Serial1.println("Setup OK!");

}

void loop() 
{  
  while(Serial.available() > 0)//LETTURA DATI GPS
    gps.encode(Serial.read());

  webSocket.loop();
  server.handleClient();
  ArduinoOTA.handle();
}
