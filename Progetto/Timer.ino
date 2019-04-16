
void Timer_interrupt()
{
	Acc = (X + Y + Z) / 3;
  //Serial1.println(Acc);
	InRun_ACC = IsInRun_ACC(Acc);
}
