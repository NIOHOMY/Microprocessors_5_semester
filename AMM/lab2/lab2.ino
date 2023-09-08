#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SevSeg.h>

#define DHTPIN 2          // Pin connected to DHT sensor
#define DHTTYPE DHT22     // DHT sensor type

DHT_Unified dht(DHTPIN, DHTTYPE);
SevSeg sevseg;

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Display setup
  byte numDigits = 4; 
  byte digitPins[] = {6, 7, 8, 9}; 
  byte segmentPins[] = {10, 11, 12, 13, A0, A1, A2, A3}; 
  bool resistorsOnSegments = true; 
  byte hardwareConfig = COMMON_CATHODE; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
}

void loop() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temperature = event.temperature;
  dht.humidity().getEvent(&event);
  float humidity = event.relative_humidity;

  displayTemperatureCelsius(temperature);

  delay(2000);

  displayHumidity(humidity);

  delay(2000);

  displayTemperatureFahrenheit(temperature);

  delay(2000);

  displayHumidity(humidity);

  delay(2000);
}

void displayTemperatureCelsius(float temperature) {
  int tempInt = int(temperature); 

  sevseg.setNumber(tempInt, 1); 
  sevseg.refreshDisplay();
  delay(2000);

  sevseg.setNumber(int((temperature - tempInt) * 100), 2); 
  sevseg.refreshDisplay();
  delay(2000);

  sevseg.setNumber(1, 3); 
  sevseg.refreshDisplay();
  delay(2000);
}

void displayTemperatureFahrenheit(float temperature) {
  int tempInt = int(temperature * 1.8 + 32); 

  sevseg.setNumber(2, 1); 
  sevseg.refreshDisplay();
  delay(2000);

  sevseg.setNumber(tempInt, 2); 
  sevseg.refreshDisplay();
  delay(2000);
}

void displayHumidity(float humidity) {
  int humInt = int(humidity); 

  sevseg.setNumber(humInt, 3); 
  sevseg.refreshDisplay();
  delay(2000);

  sevseg.setNumber(int((humidity - humInt) * 100), 4); 
  sevseg.refreshDisplay();
  delay(2000);

  sevseg.setNumber(3, 4); 
  sevseg.refreshDisplay();
  delay(2000);
}
