
void MMA8451_Setup()
{  
  Serial1.println("Adafruit MMA8451 test!");
  if (!mma.begin()) 
  {
    Serial1.println("Couldnt start");
    while (1);
  }
  Serial1.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_8_G);
  Serial1.print("Range = "); 
  Serial1.print(2 << mma.getRange());  
  Serial1.println("G");
}

void Dati_MMA8451()
{
  mma.read();
  X = abs(mma.x);
  Y = abs(mma.y);
  Z = abs(mma.z);
}

bool IsInRun_ACC(long Acc_value)//DEFINISCE SE SIEAMO IN MOVIMENTO
{
  if(Acc_value >= IS_IN_RUN_LIMIT_ACC && N_ACC_value <= IS_IN_RUN_NUMBER_ACC)
  {
      N_ACC_value ++;
  }
  else if(Acc_value < IS_IN_RUN_LIMIT_ACC && N_ACC_value > 0)
  {
      N_ACC_value --;
  }
  else
  {}

  if(N_ACC_value >= 1000 / TIMER_TIME_MS)//SE IN MOVIMENTO PER 1000ms
  {
    return true;
  }
  else if(N_ACC_value <= 0)
  {
    return false;    
  }
}

