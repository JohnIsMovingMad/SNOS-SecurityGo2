#include <Arduino.h>

// Pin Definitions
const int motionSensorPin = 2;      // Motion sensor connected to digital pin 2
const int ledPin = 13;              // LED Pin (to indicate motion detected)
const int buzzerPin = 12;           // Buzzer Pin (for alert sound)
const int alertDelay = 5000;        // Delay for alert in milliseconds (5 seconds)

// Global Variables
bool motionDetected = false;        // Flag to track motion detection state
unsigned long lastMotionTime = 0;   // To store the last motion detection timestamp
unsigned long alertTime = 0;        // Time when alert was last triggered

void setup() {
    // Initialize Serial communication for debugging and monitoring
    Serial.begin(9600);             // Begin serial communication at 9600 baud rate
    
    // Initialize sensor pins
    pinMode(motionSensorPin, INPUT); // Motion sensor is an input
    pinMode(ledPin, OUTPUT);         // LED is an output (to indicate motion)
    pinMode(buzzerPin, OUTPUT);      // Buzzer is an output (to alert user)

    // Initialize the pins to LOW state (default OFF state)
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    // Print a startup message
    Serial.println("System Initialized. Waiting for motion...");
}

void loop() {
    // Read the motion sensor value (HIGH = motion detected, LOW = no motion)
    int motionValue = digitalRead(motionSensorPin);

    // Print the current status to the Serial Monitor
    if (motionValue == HIGH) {
        Serial.println("Motion Detected!");
        motionDetected = true;  // Flag motion as detected
        lastMotionTime = millis(); // Update the last motion time
    } else {
        Serial.println("No Motion.");
        motionDetected = false; // Flag motion as not detected
    }

    // If motion is detected, trigger alert actions
    if (motionDetected) {
        // Turn on the LED as a visual indicator
        digitalWrite(ledPin, HIGH);

        // Trigger the buzzer for alert sound (if not already triggered)
        if (millis() - alertTime >= alertDelay) {
            digitalWrite(buzzerPin, HIGH);  // Activate buzzer
            Serial.println("Alert: Motion detected - Buzzer On!");
            alertTime = millis();           // Record the alert time
        }

        // Check if 5 seconds have passed to turn off the alert system
        if (millis() - lastMotionTime >= alertDelay) {
            resetAlertSystem(); // Reset the alert system after 5 seconds
        }
    } else {
        // If no motion is detected, turn off the LED and buzzer
        resetAlertSystem();
    }

    delay(200); // Small delay for stability and debouncing
}

// Reset the alert system by turning off the buzzer and LED
void resetAlertSystem() {
    digitalWrite(ledPin, LOW);         // Turn off the LED
    digitalWrite(buzzerPin, LOW);      // Turn off the buzzer
    Serial.println("Alert system reset.");
}
