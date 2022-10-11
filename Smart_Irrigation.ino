/***********************************************************************
 * Project:  Smart Irrigation System.
 * Powered by arduino
 * Author: Erick Muuo
 * Contact: hearteric57@gmail.com
 * 
 ***********************************************************************/
 
#define MOISTURE_SENSOR_IN A0  // sets the digital input pin
#define RELAYPIN 7
#define BAUDRATE 9600  // sets the baud rate
#define DRYPIN 8
#define WETPIN 9  // variable to hold the sensor reading value'
#define WATERING_PIN 10
#define WATER_THRESHOLD 195
#define DRY_THRESHOLD 450




void setup() {
  // Open serial monitor
  Serial.begin(BAUDRATE);
  pinMode(RELAYPIN, OUTPUT);
  pinMode(DRYPIN, OUTPUT);
  pinMode(WETPIN, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.println("Initializing...\n");

}

float sensorValue = 0;
float percentage = 0.0f;

void loop() {

  if(Serial.available() > 0)
  {
    int buff = Serial.read();

    while(buff){
      digitalWrite(RELAYPIN, HIGH);
      digitalWrite(WATERING_PIN, HIGH);
      delay(5000);
      break;
    }
  }
  sensorValue = analogRead(MOISTURE_SENSOR_IN); // read the sensor input
  percentage = map(sensorValue, WATER_THRESHOLD, DRY_THRESHOLD, 100, 0.0);

  
  if(percentage <= 50)
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

  if(digitalRead(RELAYPIN) == 1)
  {
    digitalWrite(WETPIN, LOW);
    digitalWrite(DRYPIN, LOW);
    digitalWrite(WATERING_PIN, HIGH);
  }


   
  Serial.println(percentage);  // log the sensor value to the screen
  Serial.end();
  Serial.begin(BAUDRATE);

  delay(5000);

}
