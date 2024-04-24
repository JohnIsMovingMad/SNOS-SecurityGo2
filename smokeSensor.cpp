#include <Arduino.h>

// Define sensor pin
const int smokeSensorPin = A0; // Smoke sensor connected to analog pin A0

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
}

void loop() {
    // Read sensor value
    int sensorValue = analogRead(smokeSensorPin); // Read the analog value from the smoke sensor pin

    // Display sensor value
    Serial.print("Smoke Sensor Value: ");
    Serial.println(sensorValue); // Print the sensor value to the Serial Monitor

    // Add logic to trigger actions based on sensor value
    if (sensorValue > 500) {
        Serial.println("Smoke Detected!"); // Print a message if smoke is detected
    }

    // Delay for stability
    delay(1000); // Delay for 1 second before reading the sensor value again
}