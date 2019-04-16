
void Timer_interrupt()
{
	Dati_MMA8451();
	Acc = (X + Y + Z) / 3;
  //Serial1.println(Acc);
	InRun_ACC = IsInRun_ACC(Acc);
}
