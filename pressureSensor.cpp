#include <Arduino.h>

// Define sensor pin
const int pressureSensorPin = A0; // Pressure sensor connected to analog pin A0

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
}

void loop() {
    // Read sensor value
    int sensorValue = analogRead(pressureSensorPin); // Read the analog value from the pressure sensor pin

    // Convert sensor value to pressure in kPa (based on sensor calibration)
    float pressurekPa = sensorValue * 0.0048828125; // Conversion factor for 5V Arduino board

    // Display pressure reading
    Serial.print("Pressure (kPa): ");
    Serial.println(pressurekPa); // Print the pressure reading to the Serial Monitor

    // Delay for stability
    delay(1000); // Delay for 1 second before reading the sensor value again
}