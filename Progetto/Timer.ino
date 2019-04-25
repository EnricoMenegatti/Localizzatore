
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
    //Dati_GPS();
    //temp = gps.location.lat();
    Serial1.print(gps.location.lat(), 6);
    smartDelay(0);
    Serial1.print(", ");
    Serial1.println(gps.speed.kmph(),2);
    smartDelay(0);
    //printFloat(gps.location.lat(), 1, 11, 6);
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
