#include <Arduino.h>

// Pin Definitions
const int temperatureSensorPin = A0;  // Temperature sensor connected to analog pin A0
const int alertPin = 8;               // Pin for alert system (e.g., buzzer or LED)

// Threshold Constants
const float minTempThreshold = 10.0;  // Minimum acceptable temperature (°C)
const float maxTempThreshold = 30.0;  // Maximum acceptable temperature (°C)

// Calibration Constants
const float referenceVoltage = 5.0;   // Reference voltage for the ADC (5V on Arduino)
const int adcMaxValue = 1024;         // Maximum ADC value for 10-bit resolution

// Variables
float temperatureCelsius = 0.0;       // Store the calculated temperature in Celsius
int sensorValue = 0;                  // Raw sensor value from the analogRead()

// Function Prototypes
void checkTemperature(float temperature);
void activateAlertSystem(bool activate);
void printTemperature(float temperature);

void setup() {
    // Initialize serial communication for monitoring
    Serial.begin(9600);

    // Set the alert pin as an output (LED or buzzer)
    pinMode(alertPin, OUTPUT);

    // Ensure the alert system is initially off
    activateAlertSystem(false);
}

void loop() {
    // Read the raw value from the temperature sensor
    sensorValue = analogRead(temperatureSensorPin);
    
    // Convert the sensor value to voltage
    float voltage = (sensorValue * referenceVoltage) / adcMaxValue;

    // Convert the voltage to temperature (assuming a TMP36 sensor with a 500mV offset at 25°C)
    // Adjust this calculation based on the sensor’s datasheet for better accuracy
    temperatureCelsius = (voltage - 0.5) * 100.0;

    // Print the temperature to the Serial Monitor
    printTemperature(temperatureCelsius);

    // Check if the temperature is within the defined range
    checkTemperature(temperatureCelsius);

    // Delay for stability (1 second)
    delay(1000);
}

// Function to check the temperature and activate alert if needed
void checkTemperature(float temperature) {
    if (temperature < minTempThreshold || temperature > maxTempThreshold) {
        // If the temperature is out of range, trigger the alert system
        activateAlertSystem(true);
    } else {
        // If the temperature is within range, deactivate the alert system
        activateAlertSystem(false);
    }
}

// Function to activate or deactivate the alert system (LED or buzzer)
void activateAlertSystem(bool activate) {
    if (activate) {
        // Turn on the alert system (e.g., buzzer or LED)
        digitalWrite(alertPin, HIGH);
    } else {
        // Turn off the alert system
        digitalWrite(alertPin, LOW);
    }
}

// Function to print the current temperature with a clear message to Serial Monitor
void printTemperature(float temperature) {
    Serial.print("Current Temperature (°C): ");
    Serial.println(temperature);
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    Serial.println("-----------------------------------");
}
