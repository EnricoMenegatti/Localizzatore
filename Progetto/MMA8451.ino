
void MMA8451_Setup()
{  
  Serial.println("Adafruit MMA8451 test!");
  if (!mma.begin()) 
  {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_8_G);
  Serial.print("Range = "); 
  Serial.print(2 << mma.getRange());  
  Serial.println("G");
}

void Event_MMA8451()
{
  mma.read();
  X = abs(mma.x);
  Y = abs(mma.y);
  Z = abs(mma.z);
}
