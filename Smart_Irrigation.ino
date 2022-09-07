/***********************************************************************
 * Project:  Smart Irrigation System.
 * Powered by arduino
 * Author: Erick Muuo
 * Contact: hearteric57@gmail.com
 * 
 ***********************************************************************/
 
#define ANALOGIN 0  // sets the analog input pin
#define BAUDRATE 19200  // sets the baud rate
int sensorValue = 0;  // variato hold the sensor reading value
 


void setup() {
  // Open serial monitor
  Serial.begin(BAUDRATE);

  Serial.println("Initializing...\n");

}

void loop() {
  sensorValue = analogRead(ANALOGIN); // read the sensor input

  Serial.println(sensorValue);  // log the sensor value to the screen

  delay(1000);

}
