#include <Arduino.h>
#include <Wire.h>  // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // For LCD Display
#include <Adafruit_Sensor.h>  // For integrating additional sensors
#include <Adafruit_BME280.h>  // Example of another sensor for real-world application

// Pin Definitions
const int smokeSensorPin = A0; // Smoke sensor connected to analog pin A0
const int ledPin = 13;         // Built-in LED to indicate smoke detection
const int buzzerPin = 12;      // Buzzer for audio alert on smoke detection

// Define thresholds and variables
const int smokeThreshold = 500;  // Threshold for detecting smoke
int smokeLevel = 0;              // Variable to store the smoke sensor value
bool smokeAlertActive = false;   // Flag to track if smoke alert is active

// Initialize the LCD display (Optional: can be used for real-time feedback)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD I2C address and dimensions (16x2)

// BME280 Sensor for additional environmental data (Optional)
Adafruit_BME280 bme;  // I2C

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Setup pin modes
  pinMode(smokeSensorPin, INPUT);   // Set smoke sensor pin as input
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
  pinMode(buzzerPin, OUTPUT);       // Set Buzzer pin as output

  // Initialize LCD Display
  lcd.begin(16, 2);
  lcd.print("Smoke Detector");
  
  // Initialize the BME280 sensor (Optional for additional environmental readings)
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    lcd.setCursor(0, 1);
    lcd.print("Sensor Error!");
    delay(2000); // Wait before restarting
    return;
  }

  // Wait for the BME280 sensor to initialize
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor Active");

  // Initial system feedback
  Serial.println("System Initialized, Waiting for Smoke Detection...");
}

void loop() {
  // Read the value from the smoke sensor
  smokeLevel = analogRead(smokeSensorPin);

  // Output the sensor value to Serial Monitor for debugging
  Serial.print("Smoke Sensor Value: ");
  Serial.println(smokeLevel);

  // Display smoke level on LCD
  lcd.setCursor(0, 0);
  lcd.print("Smoke Level: ");
  lcd.print(smokeLevel);

  // Check for smoke presence and take action
  if (smokeLevel > smokeThreshold) {
    if (!smokeAlertActive) {
      smokeAlertActive = true;  // Set flag to prevent duplicate alerts
      handleSmokeDetection();   // Function to handle alert actions
    }
  } else {
    smokeAlertActive = false;  // Reset the alert flag when smoke is not detected
    turnOffAlerts();           // Turn off alerts when no smoke is detected
  }

  // Optional: Read environmental data from BME280 sensor (e.g., temperature, humidity)
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;  // Convert to hPa

  // Display environmental data on LCD (for optional use)
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  // Delay for stability
  delay(1000);  // Delay 1 second before reading again
}

void handleSmokeDetection() {
  // Turn on the LED and buzzer when smoke is detected
  digitalWrite(ledPin, HIGH);     // Turn on the LED to indicate smoke detection
  digitalWrite(buzzerPin, HIGH);  // Sound the buzzer

  // Print a message to Serial Monitor
  Serial.println("Smoke Detected! Alert Triggered!");

  // Display message on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smoke Detected!");
  
  // Optional: Send a message to alert a monitoring system (like an SMS or email)
  sendAlert(); // Call function to send alerts (e.g., email/SMS)

  // Wait to allow the alert to persist
  delay(2000);  // Keep the alert active for 2 seconds
}

void turnOffAlerts() {
  // Turn off the LED and buzzer when smoke is no longer detected
  digitalWrite(ledPin, LOW);     // Turn off the LED
  digitalWrite(buzzerPin, LOW);  // Turn off the buzzer

  // Reset the LCD to normal mode
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("No Smoke Detected");
}

void sendAlert() {
  // I thought of this function to send SMS, Email, or HTTP requests for real-world integration, and it can be extended 
  Serial.println("Sending Alert...");
}
