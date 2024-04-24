#include <Arduino.h>

// Define sensor pin
const int motionSensorPin = 2; // Motion sensor connected to digital pin 2

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Set sensor pin as input
    pinMode(motionSensorPin, INPUT);
}

void loop() {
    // Read sensor value
    int motionValue = digitalRead(motionSensorPin); // Read the digital value from the motion sensor pin

    // Display sensor value
    Serial.print("Motion Sensor Value: ");
    Serial.println(motionValue); // Print the sensor value to the Serial Monitor

    // Add logic to trigger actions based on sensor value
    if (motionValue == HIGH) {
        Serial.println("Motion Detected!"); // Print a message if motion is detected
    }

    // Delay for stability
    delay(1000); // Delay for 1 second before reading the sensor value again
}