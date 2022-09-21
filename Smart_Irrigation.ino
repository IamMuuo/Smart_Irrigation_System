/***********************************************************************
 * Project:  Smart Irrigation System.
 * Powered by arduino
 * Author: Erick Muuo
 * Contact: hearteric57@gmail.com
 * 
 ***********************************************************************/
 
#define DIGITAL_IN A0  // sets the digital input pin
#define RELAYPIN 7
#define BAUDRATE 19200  // sets the baud rate
#define DRYPIN 8
#define WETPIN 9  // variable to hold the sensor reading value'

float sensorValue = 0;


void setup() {
  // Open serial monitor
  Serial.begin(BAUDRATE);
  pinMode(RELAYPIN, OUTPUT);
  pinMode(DRYPIN, OUTPUT);
  pinMode(WETPIN, OUTPUT);
  
  Serial.println("Initializing...\n");

}

void loop() {
  sensorValue = analogRead(DIGITAL_IN); // read the sensor input

  if(sensorValue >= 500)
  {
      Serial.println("Dry soil detected. Turning on pump...\n");
      digitalWrite(RELAYPIN, HIGH);
      digitalWrite(DRYPIN, HIGH);
      digitalWrite(WETPIN, LOW);
  }
  else
  {
      Serial.println("Soil is wet, turning off pump..\n");
      digitalWrite(RELAYPIN, LOW); 
      digitalWrite(DRYPIN, LOW);
      digitalWrite(WETPIN, HIGH);
  }

  Serial.println(sensorValue);  // log the sensor value to the screen

  delay(1000);


}
