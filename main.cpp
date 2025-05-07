// john-everything.cpp
// Comprehensive Security System Integration
// Developed by John

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <fstream>

// Mock sensor functions simulating real-life behavior
bool motionSensorTriggered() {
    // Simulate sensor data (replace with actual sensor reading logic)
    return true; // Motion detected
}

bool fireSensorTriggered() {
    // Simulate sensor data (replace with real fire sensor interface)
    return true; // Fire detected
}

bool gasLeakSensorTriggered() {
    // Simulate sensor data (replace with actual gas sensor logic)
    return true; // Gas leak detected
}

// Utility function to log events with timestamps
void logEvent(const std::string& event) {
    std::ofstream logFile("system_log.txt", std::ios::app);
    std::time_t now = std::time(nullptr);
    logFile << std::ctime(&now) << ": " << event << "\n";
    logFile.close();
}

// Mock alert system
void alertAuthorities(const std::string& eventType) {
    std::cout << "[ALERT] Notifying authorities about: " << eventType << "...\n";
    logEvent("Authority notified: " + eventType);
    // In real systems, integrate with SMS, email, or IoT alert APIs here
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[INFO] Authorities successfully alerted.\n";
}

void activateFireSuppressionSystem() {
    std::cout << "[ACTION] Activating fire suppression system...\n";
    logEvent("Fire suppression system activated");
    // Trigger physical system through GPIO/relay control in real hardware
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[INFO] Fire suppression system active.\n";
}

void initiateEvacuation() {
    std::cout << "[ACTION] Evacuation procedures initiated. Broadcasting alarms...\n";
    logEvent("Evacuation procedure initiated");
    // Trigger physical alarms and notifications
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[INFO] Evacuation broadcast complete.\n";
}

void detectMotion() {
    std::cout << "[SYSTEM] Checking motion sensors...\n";
    if (motionSensorTriggered()) {
        std::cout << "[DETECTED] Motion detected!\n";
        logEvent("Motion detected");
        alertAuthorities("Intrusion detected");
    } else {
        std::cout << "[INFO] No motion detected.\n";
    }
}

void detectFire() {
    std::cout << "[SYSTEM] Checking fire sensors...\n";
    if (fireSensorTriggered()) {
        std::cout << "[DETECTED] Fire detected!\n";
        logEvent("Fire detected");
        activateFireSuppressionSystem();
        alertAuthorities("Fire emergency");
    } else {
        std::cout << "[INFO] No fire detected.\n";
    }
}

void detectGasLeak() {
    std::cout << "[SYSTEM] Checking gas leak sensors...\n";
    if (gasLeakSensorTriggered()) {
        std::cout << "[DETECTED] Gas leak detected!\n";
        logEvent("Gas leak detected");
        initiateEvacuation();
        alertAuthorities("Gas leak emergency");
    } else {
        std::cout << "[INFO] No gas leak detected.\n";
    }
}

void displayMenu() {
    std::cout << "\n========================\n";
    std::cout << " Security Control Panel \n";
    std::cout << "========================\n";
    std::cout << "1. Detect Motion\n";
    std::cout << "2. Detect Fire\n";
    std::cout << "3. Detect Gas Leak\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;

    std::cout << "[SYSTEM] Initializing Smart Security Network...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[SYSTEM] Ready. Monitoring enabled.\n";

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                detectMotion();
                break;
            case 2:
                detectFire();
                break;
            case 3:
                detectGasLeak();
                break;
            case 4:
                std::cout << "[SYSTEM] Shutting down security interface...\n";
                logEvent("System shut down by user");
                break;
            default:
                std::cout << "[ERROR] Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
