#include "DHT.h"

#define DHTPIN 5     // DHT11 data pin connected to D2
#define DHTTYPE DHT11  // Sensor type
#define LEDPIN 13      // LED on digital pin 9

DHT dht(DHTPIN, DHTTYPE);

float limitTemp = 29.50;  // Temperature limit to switch OFF LED

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature(); // Read temp in °C

  // Check if reading is valid
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT11!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (temperature >= limitTemp) {
    digitalWrite(LEDPIN, LOW);   // LED OFF
  } else {
    digitalWrite(LEDPIN, HIGH);  // LED ON
  }

  delay(1000); // Read every 1 second
}
