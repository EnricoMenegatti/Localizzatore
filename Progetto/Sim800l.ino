
void SIM_Setup()
{
  Serial1.println(F("*** SIMCom Module IoT Example ***"));

  gsm.begin(9600); // Default SIM800 shield baud rate
  
  Serial1.println(F("Configuring to 9600 baud"));
  gsm.println("AT+IPR=9600"); // Set baud rate
  delay(100); // Short pause to let the command run
  gsm.begin(9600);
  if (! fona.begin(gsm)) 
  {
    Serial1.println(F("Couldn't find FONA"));
    while(1); // Don't proceed if it couldn't find the device
  }

  type = fona.type();
  Serial1.println(F("FONA is OK"));
  Serial1.print(F("Found "));
  switch (type) 
  {
    case SIM800L:
      Serial1.println(F("SIM800L")); break;
    case SIM800H:
      Serial1.println(F("SIM800H")); break;
    case SIM808_V1:
      Serial1.println(F("SIM808 (v1)")); break;
    case SIM808_V2:
      Serial1.println(F("SIM808 (v2)")); break;
    case SIM5320A:
      Serial1.println(F("SIM5320A (American)")); break;
    case SIM5320E:
      Serial1.println(F("SIM5320E (European)")); break;
    case SIM7000A:
      Serial1.println(F("SIM7000A (American)")); break;
    case SIM7000C:
      Serial1.println(F("SIM7000C (Chinese)")); break;
    case SIM7000E:
      Serial1.println(F("SIM7000E (European)")); break;
    case SIM7000G:
      Serial1.println(F("SIM7000G (Global)")); break;
    case SIM7500A:
      Serial1.println(F("SIM7500A (American)")); break;
    case SIM7500E:
      Serial1.println(F("SIM7500E (European)")); break;
    default:
      Serial1.println(type); break;
  }
  
  // Print module IMEI number.
  uint8_t imeiLen = fona.getIMEI(imei);
  if (imeiLen > 0) 
  {
    Serial1.print("Module IMEI: "); Serial1.println(imei);
  }

  // Set modem to full functionality
  fona.setFunctionality(1); // AT+CFUN=1

  // Configure a GPRS APN, username, and password.
  // You might need to do this to access your network's GPRS/data
  // network.  Contact your provider for the exact APN, username,
  // and password values.  Username and password are optional and
  // can be removed, but APN is required.
  //fona.setNetworkSettings(F("your APN"), F("your username"), F("your password"));
  //fona.setNetworkSettings(F("m2m.com.attz")); // For AT&T IoT SIM card
  //fona.setNetworkSettings(F("telstra.internet")); // For Telstra (Australia) SIM card - CAT-M1 (Band 28)
  fona.setNetworkSettings(F("mobile.vodafone.it")); // For Hologram SIM card

  // Optionally configure HTTP gets to follow redirects over SSL.
  // Default is not to follow SSL redirects, however if you uncomment
  // the following line then redirects over SSL will be followed.
  //fona.setHTTPSRedirect(true);

  /*
  // Other examples of some things you can set:
  fona.setPreferredMode(38); // Use LTE only, not 2G
  fona.setPreferredLTEMode(1); // Use LTE CAT-M only, not NB-IoT
  fona.setOperatingBand("CAT-M", 12); // AT&T uses band 12
//  fona.setOperatingBand("CAT-M", 13); // Verizon uses band 13
  fona.enableRTC(true);
  
  fona.enableSleepMode(true);
  fona.set_eDRX(1, 4, "0010");
  fona.enablePSM(true);

  // Set the network status LED blinking pattern while connected to a network (see AT+SLEDS command)
  fona.setNetLED(true, 2, 64, 3000); // on/off, mode, timer_on, timer_off
  fona.setNetLED(false); // Disable network status LED
  */
}

void Notifica()
{
  /*Serial1.print("Connect to Internet: ");
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
  Serial1.println(gsm.gprsCloseConn());//CHIUDI CONNESSIONE INTERNET*/
}
