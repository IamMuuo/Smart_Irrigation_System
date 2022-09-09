/***********************************************************************
 * Project:  Smart Irrigation System.
 * Powered by arduino
 * Author: Erick Muuo
 * Contact: hearteric57@gmail.com
 * 
 ***********************************************************************/
 
#define DIGITAL_IN 9  // sets the analog input pin
#define BAUDRATE 19200  // sets the baud rate
int sensorValue = 0;  // variable to hold the sensor reading value
 


void setup() {
  // Open serial monitor
  Serial.begin(BAUDRATE);

  Serial.println("Initializing...\n");

}

void loop() {
  sensorValue = digitalRead(DIGITAL_IN); // read the sensor input

  if(sensorValue == 1)
  {
      Serial.println("Dry soil detected. Turning on pump...\n");
  }
  else
  {
      Serial.println("Soil is wet, turning off pump..\n");
  }

  Serial.println(sensorValue);  // log the sensor value to the screen

  delay(1000);

}
