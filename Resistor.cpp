#include <iostream>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

// Define color codes for resistor bands
unordered_map<string, int> COLOR_CODES = {
    {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
    {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
    {"gray", 8}, {"white", 9}
};

// Define multipliers for resistor colors
unordered_map<string, int> MULTIPLIERS = {
    {"black", 1}, {"brown", 10}, {"red", 100}, {"orange", 1000},
    {"yellow", 10000}, {"green", 100000}, {"blue", 1000000},
    {"gold", 1}, {"silver", 0.1}
};

// Define tolerance values for resistor colors
unordered_map<string, string> TOLERANCE = {
    {"brown", "±1%"}, {"red", "±2%"}, {"gold", "±5%"}, {"silver", "±10%"}
};

// Function to calculate resistance from color bands
void calculateResistance() {
    string band1, band2, multiplier, tolerance;
    
    // Display available colors for the 1st and 2nd bands
    cout << "\nAvailable colors for 1st and 2nd band:\n";
    for (const auto& pair : COLOR_CODES) cout << pair.first << " ";  // Print color options
    cout << "\nEnter the 1st color: ";
    cin >> band1;  // Get user input for the first band
    cout << "Enter the 2nd color: ";
    cin >> band2;  // Get user input for the second band

    // Display available colors for the multiplier
    cout << "\nAvailable multiplier colors:\n";
    for (const auto& pair : MULTIPLIERS) cout << pair.first << " ";  // Print multiplier options
    cout << "\nEnter the multiplier color: ";
    cin >> multiplier;  // Get user input for the multiplier band

    // Display available colors for tolerance
    cout << "\nAvailable tolerance colors:\n";
    for (const auto& pair : TOLERANCE) cout << pair.first << " ";  // Print tolerance options
    cout << "\nEnter the tolerance color: ";
    cin >> tolerance;  // Get user input for tolerance band

    // Validate the user input and calculate the resistance
    if (COLOR_CODES.find(band1) != COLOR_CODES.end() && COLOR_CODES.find(band2) != COLOR_CODES.end() && MULTIPLIERS.find(multiplier) != MULTIPLIERS.end()) {
        int resistance = (COLOR_CODES[band1] * 10 + COLOR_CODES[band2]) * MULTIPLIERS[multiplier];  // Calculate resistance
        string toleranceValue = TOLERANCE.count(tolerance) ? TOLERANCE[tolerance] : "Unknown tolerance";  // Get tolerance if valid
        cout << "\nResistance: " << resistance << " Ω " << toleranceValue << endl;  // Output result
    } else {
        cout << "\nInvalid color code entered. Please try again." << endl;  // Error message for invalid input
    }
}

// Function to suggest color bands based on a given resistance value
void suggestColor() {
    double resistance;
    string tolerance;
    
    // Get resistance and tolerance inputs from the user
    cout << "\nEnter the resistance value in Ω: ";
    cin >> resistance;
    cout << "Enter the tolerance (1%, 2%, 5%, or 10%): ";
    cin >> tolerance;

    // Check for matching color bands for the given resistance value
    for (const auto& band1 : COLOR_CODES) {
        for (const auto& band2 : COLOR_CODES) {
            for (const auto& multiplier : MULTIPLIERS) {
                // Calculate resistance based on current color bands
                double calculatedResistance = (band1.second * 10 + band2.second) * multiplier.second;
                // Check if the calculated resistance matches the input resistance
                if (fabs(calculatedResistance - resistance) < 0.001) {
                    // If tolerance is valid, output corresponding color bands
                    if (TOLERANCE.find(tolerance) != TOLERANCE.end()) {
                        cout << "\nColor Bands: " << band1.first << ", " << band2.first << ", " << multiplier.first << ", " << TOLERANCE[tolerance] << endl;
                        return;
                    } else {
                        cout << "\nInvalid tolerance value entered." << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "\nNo matching color code found." << endl;  // If no match is found, display this message
}

// Main function for user interaction
int main() {
    int choice;
    
    while (true) {
        // Display the menu with available options
        cout << "\nChoose an option:" << endl;
        cout << "1. Calculate resistance from color bands." << endl;
        cout << "2. Suggest color bands from resistance." << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Execute the appropriate method based on user input
        switch (choice) {
            case 1:
                calculateResistance();  // Call the method to calculate resistance
                break;
            case 2:
                suggestColor();  // Call the method to suggest color bands
                break;
            case 3:
                cout << "\nExiting the program. Goodbye!" << endl;
                return 0;  // Exit the program
            default:
                cout << "\nInvalid choice. Please try again." << endl;  // Error message for invalid choice
        }
    }
}
