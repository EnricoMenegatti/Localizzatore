
void Timer_interrupt()
{
  Timer_cont++;
	Dati_MMA8451();
	Acc = (X + Y + Z) / 3;
  Serial1.println(Acc);
	InRun_ACC = IsInRun_ACC();

  Serial1.print("In movimento? ");
  Serial1.print(N_ACC_value);
  Serial1.print(", ");
  Serial1.println(InRun_ACC);
}
