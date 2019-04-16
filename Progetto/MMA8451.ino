
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

void Event_MMA8451()
{
  mma.read();
  X = abs(mma.x);
  Y = abs(mma.y);
  Z = abs(mma.z);
}
