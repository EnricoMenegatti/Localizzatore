
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

void Notifica()
{
  Serial1.print("Connect to Internet: ");
  Serial1.println(gsm.gprsConnectBearer());//APRI CONNESSIONE INTERNET
  delay(5000);
  
  // Set Gmail Account
  // If you take an error when sending email with google, please check display unlock captcha setting on google
  // please use this url for this.
  // https://www.google.com/accounts/DisplayUnlockCaptcha
  // for gmail, dont use @gmail.com on your username.
  // at the last, if you take an authendication error, please check 2 way verification settings on your account.
  Serial1.print("Set gmail smtp configuration: ");
  Serial1.println(gsm.emailSMTPGmail("enricomenegatti13", "Menegatti13"));

  Serial1.print("Write email to someone: ");
  // In body, if you want to use break, use \b, for tab use \t on your message body string. Only use Ascii characters on title and body, otherwise your mail not send.
  Serial1.println(gsm.emailSMTPWrite("enricomenegatti13@gmail.com", "enri13@hotmail.it", "Allarme", "Attenzione in movimento!!!"));

  delay(1000);

  Serial1.print("Send email... : ");
  Serial1.println(gsm.emailSMTPSend());//INVIA EMAIL
  
  // Close internet connection
  Serial1.print("Close Internet: ");
  Serial1.println(gsm.gprsCloseConn());//CHIUDI CONNESSIONE INTERNET
}
