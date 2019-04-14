
void SIM_Setup()
{
  gsm.start(BAUD);
  delay(1000);

  gsm.listen();
  Serial.print("Manufacturer:\t\t");
  Serial.println(gsm.moduleManufacturer());
  delay(250);
  Serial.print("Model:\t\t\t");
  Serial.println(gsm.moduleModel());
  delay(250);
  Serial.print("Revision:\t\t");
  Serial.println(gsm.moduleRevision());
  delay(250);
  Serial.print("IMEI:\t\t\t");
  Serial.println(gsm.moduleIMEI());
  delay(250);
  Serial.print("IMSI:\t\t\t");
  Serial.println(gsm.moduleIMSI());
  delay(250);
  Serial.print("ICCID:\t\t\t");
  Serial.println(gsm.moduleICCID());
  delay(250);
  Serial.print("Is Connected?:\t\t");
  Serial.println(gsm.isRegistered());
  delay(250);
  Serial.print("Signal Quality:\t\t");
  Serial.println(gsm.signalQuality());
  delay(250);
  Serial.print("Operator:\t\t");
  Serial.println(gsm.operatorName());
  delay(250);
  Serial.print("Operator From Sim:\t");
  Serial.println(gsm.operatorNameFromSim());
  delay(250);
}

void SIM_AT()
{

}

  
