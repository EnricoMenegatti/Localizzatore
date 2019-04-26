
void Timer_Acc_interrupt()
{
  Timer_cont++;
	Dati_MMA8451();
	Acc = (X + Y + Z) / 3;
  Serial1.println(Acc);
	InRun_ACC = IsInRun_ACC();

  if(InRun_ACC == true)
  {
    Timer_Acc.detach();
  }
  
  Serial1.print("In movimento? ");
  Serial1.print(N_ACC_value);
  Serial1.print(", ");
  Serial1.println(InRun_ACC);
}

void Timer_gps_interrupt()
{
  if(InRun_ACC)//SE SIAMO IN RUN
  {
    Serial1.print(gps.location.lat(), 6);
    Serial1.print(", ");
    Serial1.println(gps.speed.kmph(),2);
    /*if(IsInRun_GPS(gps.speed.kmph(), gps.speed.isValid()))
    {
      Notifica();
    }*/
  }
}

void Timer_1_interrupt()
{
  N_ACC_value = 0;
}

void Timer_gsm_interrupt()
{
  uint8_t n = fona.getNetworkStatus();
  Serial1.print(F("Network status "));
  Serial1.print(n);
  Serial1.print(F(": "));
  if (n == 0) Serial1.println(F("Not registered"));
  if (n == 1) Serial1.println(F("Registered (home)"));
  if (n == 2) Serial1.println(F("Not registered (searching)"));
  if (n == 3) Serial1.println(F("Denied"));
  if (n == 4) Serial1.println(F("Unknown"));
  if (n == 5) Serial1.println(F("Registered roaming"));
}
