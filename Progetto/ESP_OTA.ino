
void OTA_Setup() 
{
  Serial1.println("OTA Setup");
  WiFi.mode(WIFI_STA);
  WiFi.begin(HOME_ssid, HOME_pass);
  
  while (WiFi.waitForConnectResult() != WL_CONNECTED) 
  {
    Serial1.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
   ArduinoOTA.setHostname(HOST_name);

  // No authentication by default
  // ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.onStart([]() 
  {
    Serial1.println("Start");
  });
  
  ArduinoOTA.onEnd([]() 
  {
    Serial1.println("\nEnd");
  });
  
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) 
  {
    Serial1.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  
  ArduinoOTA.onError([](ota_error_t error) 
  {
    Serial1.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial1.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial1.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial1.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial1.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial1.println("End Failed");
  });
  
  ArduinoOTA.begin();
  Serial1.println("Ready");
  Serial1.print("IP address: ");
  Serial1.println(WiFi.localIP());
}
