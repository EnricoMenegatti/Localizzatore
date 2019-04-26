#include <SoftwareSerial.h>

#define  SS_RX 12            // RX PIN to receive  data
#define  SS_TX 14            // TX PIN to transmit data

SoftwareSerial ssSerial(SS_RX, SS_TX);

void setup()
{
  delay (2000);
  //
  Serial.begin(115200);        // Initialize USB Serial port
  ssSerial.begin(9600);      // Initialize SoftwareSerial port
  //
  Serial.println("--- Ports ready ---");
  Serial.println("");
}

void loop()
{
  if (ssSerial.available() > 0) Serial.write(ssSerial.read());
  if (Serial.available() > 0) ssSerial.write(Serial.read());
}
