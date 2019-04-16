 
void setup() {
  Serial.begin(9600);
  Serial.swap();
  //Serial.println("Setup 0...");
  Serial1.begin(9600);
  Serial1.println("Setup 1...");
}

void loop() 
{

  Serial.println("LOOP 0...");
  Serial1.println("LOOP 1...");
  
}
