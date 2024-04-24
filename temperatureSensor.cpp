#include <Arduino.h>

// Define sensor pin
const int temperatureSensorPin = A0; // Temperature sensor connected to analog pin A0

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
}

void loop() {
    // Read sensor value
    int sensorValue = analogRead(temperatureSensorPin); // Read the analog value from the temperature sensor pin

    // Convert sensor value to temperature in degrees Celsius
    float temperatureCelsius = (sensorValue * 5.0 / 1024.0) * 100.0;

    // Display temperature
    Serial.print("Temperature (Celsius): ");
    Serial.println(temperatureCelsius); // Print the temperature to the Serial Monitor

    // Delay for stability
    delay(1000); // Delay for 1 second before reading the sensor value again
}