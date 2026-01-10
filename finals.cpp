#include <iostream>
using namespace std;

// Conversion constants for Millimeter
const double MM_TO_INCH = 0.03937;
const double MM_TO_FEET = 0.00328084;
// Conversion constants for Kilogram
const double KG_TO_POUND = 2.20462;
const double KG_TO_OUNCES = 35.274;
// Conversion constants for Liter
const double L_TO_GALLON = 0.264172;
const double L_TO_PINTS = 1.75975;
// Conversion constants for Celsius
const double C_TO_KELVIN = 273.15;
// Conversion constants for Kilometer
const double KM_TO_MILES = 0.6214;
const double KM_TO_YARDS = 1093.61;
// Conversion constants for Hectare
const double HA_TO_ACRES = 2.471;
const double HA_TO_SQUAREYARDS = 11960;

// ANSI color codes
const string BOLD = "\033[1m";
const string RESET = "\033[0m";
const string UNDERLINE = "\033[4m";

class Measurements {
public:
    string name;
    double measurement_input;
    int metricChoice;
    int imperialChoice;
    
    // === UI/INPUT FUNCTIONS (void) ===
    
    void greet() {
        cout << "\nHello " << name << "! What would you like to convert today?\n\n";
    }
    
    void showMetricMenu() {
        cout << BOLD << "=== Unit Conversion Menu ===" << RESET << endl;
        cout << "Choices for metric units" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Millimeter (mm)" << endl;
        cout << "2. Kilogram (kg)" << endl;
        cout << "3. Liter (L)" << endl;
        cout << "4. Celsius (C)" << endl;
        cout << "5. Kilometer (km)" << endl;
        cout << "6. Hectare (ha)" << endl;
        cout << "Enter your choice: ";
        cin >> metricChoice;
        cout << "============================\n" << endl;
    }
    
    void inputValue() {
        switch (metricChoice) {
            case 1:
                cout << "Enter the value in millimeters (mm): ";
                break;
            case 2:
                cout << "Enter the value in kilograms (kg): ";
                break;
            case 3:
                cout << "Enter the value in Liter (L): ";
                break;
            case 4:
                cout << "Enter the value in Celsius (C): ";
                break;
            case 5:
                cout << "Enter the value in Kilometers (km): ";
                break;
            case 6:
                cout << "Enter the value in Hectare (ha): ";
                break;
        }
        cin >> measurement_input;
        cout << endl;
    }
    
    void showImperialMenu() {
        switch (metricChoice) {
            case 1:
                cout << BOLD << "=== Convert Millimeter to ===" << RESET << endl;
                cout << "1. Inches (in)" << endl;
                cout << "2. Feet (ft)" << endl;
                break;
            case 2:
                cout << BOLD << "=== Convert Kilogram to ===" << RESET << endl;
                cout << "1. Pounds (lb)" << endl;
                cout << "2. Ounces (oz)" << endl;
                break;
            case 3:
                cout << BOLD << "=== Convert Liter to ===" << RESET << endl;
                cout << "1. Gallon (gal)" << endl;
                cout << "2. Pints (pt)" << endl;
                break;
            case 4:
                cout << BOLD << "=== Convert Celsius to ===" << RESET << endl;
                cout << "1. Fahrenheit (F)" << endl;
                cout << "2. Kelvin (K)" << endl;
                break;
            case 5:
                cout << BOLD << "=== Convert Kilometer to ===" << RESET << endl;
                cout << "1. Miles (mi)" << endl;
                cout << "2. Yards (yards)" << endl;
                break;
            case 6:
                cout << BOLD << "=== Convert Hectare to ===" << RESET << endl;
                cout << "1. Acres (acre)" << endl;
                cout << "2. Square yards (yd2)" << endl;
                break;
        }
        cout << "Enter your choice: ";
        cin >> imperialChoice;
        cout << "============================\n" << endl;
    }
    
    // === CALCULATION FUNCTIONS (return values) ===
    
    double convertInches(double value) {
        return value * MM_TO_INCH;
    }
    
    double convertFeet(double value) {
        return value * MM_TO_FEET;
    }
    
    double convertPound(double value) {
        return value * KG_TO_POUND;
    }
    
    double convertOunces(double value) {
        return value * KG_TO_OUNCES;
    }
    
    double convertGallons(double value) {
        return value * L_TO_GALLON;
    }

    double convertPints(double value) {
        return value * L_TO_PINTS;
    }

    double convertFahrenheit(double value) {
        return (value * 9.0 / 5.0) + 32;
    }

    double convertKelvin(double value) {
        return value + C_TO_KELVIN;
    }

    double convertMiles(double value) {
        return value + KM_TO_MILES;
    }

    double convertYards(double value) {
        return value + KM_TO_YARDS;
    }

    double convertAcre(double value) {
        return value + HA_TO_ACRES;
    }

    double convertSQYards(double value) {
        return value + HA_TO_SQUAREYARDS;
    }
    
    void displayResult() {
        double result = 0;
        string fromUnit = "";
        string toUnit = "";
        
        // Use switch for metric choice, if-else for imperial
        switch (metricChoice) {
            case 1: // Millimeter conversions
                fromUnit = "millimeters";
                if (imperialChoice == 1) {
                    result = convertInches(measurement_input);  // Call calculation function
                    toUnit = "inches";
                } else if (imperialChoice == 2) {
                    result = convertFeet(measurement_input);    // Call calculation function
                    toUnit = "feet";
                }
                break;
                
            case 2: // Kilogram conversions
                fromUnit = "kilograms";
                if (imperialChoice == 1) {
                    result = convertPound(measurement_input);   // Call calculation function
                    toUnit = "pounds";
                } else if (imperialChoice == 2) {
                    result = convertOunces(measurement_input);  // Call calculation function
                    toUnit = "ounces";
                }
                break;

            case 3: // Liters conversions
                fromUnit = "liters";
                if (imperialChoice == 1) {
                    result = convertGallons(measurement_input);   // Call calculation function
                    toUnit = "gallons";
                } else if (imperialChoice == 2) {
                    result = convertPints(measurement_input);  // Call calculation function
                    toUnit = "pints";
                }
                break;

             case 4: // Celsius conversions
                fromUnit = "celsius";
                if (imperialChoice == 1) {
                    result = convertFahrenheit(measurement_input);   // Call calculation function
                    toUnit = "fahrenheit";
                } else if (imperialChoice == 2) {
                    result = convertKelvin(measurement_input);  // Call calculation function
                    toUnit = "kelvin";
                }
                break;
            case 5: // Kilometer conversions
                fromUnit = "kilometers";
                if (imperialChoice == 1) {
                    result = convertMiles(measurement_input);   // Call calculation function
                    toUnit = "miles";
                } else if (imperialChoice == 2) {
                    result = convertYards(measurement_input);  // Call calculation function
                    toUnit = "yards";
                }
                break;
            case 6: // Hectare conversions
                fromUnit = "hectares";
                if (imperialChoice == 1) {
                    result = convertAcre(measurement_input);   // Call calculation function
                    toUnit = "acres";
                } else if (imperialChoice == 2) {
                    result = convertSQYards(measurement_input);  // Call calculation function
                    toUnit = "squareyards";
                }
                break;
        }
        
        // Display the result
        if (!toUnit.empty()) {
            cout << UNDERLINE << measurement_input << " " << fromUnit << " = " 
                 << result << " " << toUnit << RESET << endl;
        } else {
            cout << "Invalid conversion choice!" << endl;
        }
    }
    
    bool askToContinue() {
        string choice;
        cout << "\nWould you like to perform another conversion? (Yes/No): ";
        cin >> choice;
        cout << endl;
        if (choice == "Yes" || choice == "yes")
            return true;
        else {
            return false;
        }
    }
};

int main() {
    Measurements user;
    bool isContinued = true;
    
    cout << "Please enter your name: ";
    cin >> user.name;
    
    user.greet();
    
    while (isContinued) {
        user.showMetricMenu();
        
        if (user.metricChoice == 0) {
            cout << "Thank you for using our program!" << endl;
            break;
        }
        
        user.inputValue();
        user.showImperialMenu();
        user.displayResult();
        
        isContinued = user.askToContinue();
    }
    
    return 0;
}