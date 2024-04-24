#include <iostream>
#include <string>

// Function to handle motion detection
void detectMotion() {
    std::cout << "Motion detected! Alerting authorities...\n";
    // Add code here to alert the authorities or trigger actions
}

// Function to handle fire detection
void detectFire() {
    std::cout << "Fire detected! Activating fire suppression system...\n";
    // Add code here to activate fire suppression system
}

// Function to handle gas leak detection
void detectGasLeak() {
    std::cout << "Gas leak detected! Evacuate premises...\n";
    // Add code here to initiate evacuation procedures
}

int main() {
    int choice;

    do {
        // Display menu options
        std::cout << "Security Network Operating System Menu\n";
        std::cout << "1. Detect Motion\n";
        std::cout << "2. Detect Fire\n";
        std::cout << "3. Detect Gas Leak\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Process user choice
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
            std::cout << "Exiting Security System...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}