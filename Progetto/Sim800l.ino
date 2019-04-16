
void SIM_Setup()
{
  gsm.start(9600);

  Serial1.print("Manufacturer:\t\t");
  Serial1.println(gsm.moduleManufacturer());
  delay(250);
  Serial1.print("Model:\t\t\t");
  Serial1.println(gsm.moduleModel());
  delay(250);
  Serial1.print("Revision:\t\t");
  Serial1.println(gsm.moduleRevision());
  delay(250);
  Serial1.print("IMEI:\t\t\t");
  Serial1.println(gsm.moduleIMEI());
  delay(250);
  Serial1.print("IMSI:\t\t\t");
  Serial1.println(gsm.moduleIMSI());
  delay(250);
  Serial1.print("ICCID:\t\t\t");
  Serial1.println(gsm.moduleICCID());
  delay(250);
  Serial1.print("Is Connected?:\t\t");
  Serial1.println(gsm.isRegistered());
  delay(250);
  Serial1.print("Signal Quality:\t\t");
  Serial1.println(gsm.signalQuality());
  delay(250);
  Serial1.print("Operator:\t\t");
  Serial1.println(gsm.operatorName());
  delay(250);
  Serial1.print("Operator From Sim:\t");
  Serial1.println(gsm.operatorNameFromSim());
  delay(250);
}

  
