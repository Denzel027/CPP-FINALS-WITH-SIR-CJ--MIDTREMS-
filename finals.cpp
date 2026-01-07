#include <iostream>
using namespace std;

class Measurements{
    public:
        string name;
        string choice;
        double measurement_input;
        int metricChoice;
        int imperialChoice;
        
        string greet(string userName){
            return "Hello " + userName + "!, what would you like to convert today?";
        }
        
        double convertInches(double measurement_input){
           return measurement_input * 0.03937;
        }
        
        double convertFeet(double measurement_input){
            return measurement_input * 0.00328084;
        }
        
        double convertPound(double measurement_input){
            return measurement_input * 2.20462;
        }
        
        double convertOunces(double measurement_input){
            return measurement_input * 35.274;
        }
};      

int main() {
    Measurements user;
    user.name = "";
    user.choice = "";
    user.metricChoice = 0;
    user.imperialChoice = 0;
    user.measurement_input = 0;
    bool isContinued = true;
    
    cout << "Please Enter your name: ";
    cin >> user.name;
    cout << "\n";
    
    cout << user.greet(user.name) << endl;
    cout << "\n";
    
    while(isContinued)
    {
        cout << "\n";
        cout << "Choices for metric units" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Millimeter" << endl;
        cout << "2. Kilogram" << endl;
        cout << "Enter your choice: ";
        cin >> user.metricChoice;
    
        if (user.metricChoice == 0){
            cout << "Thank you for using our program!" << endl;
            isContinued = false;
        }
        else{
            cout << "\n";
            cout << "Enter the value: ";
            cin >> user.measurement_input;
            
            if (user.metricChoice == 1){
                cout << "\n";
                cout << "Choices for Imperial units " << endl;
                cout << "1. Inches" << endl;
                cout << "2. Feet" << endl;
                cout << "Enter your choice: ";
                cin >> user.imperialChoice;
                
                if (user.imperialChoice == 1){
                    cout << user.convertInches(user.measurement_input) << " inches" << endl;
                }
                else if (user.imperialChoice == 2){
                    cout << user.convertFeet(user.measurement_input) << " feet" << endl;
                }
                else{
                    cout << "Invalid" << endl;
                }
            }
            else if (user.metricChoice == 2){
                cout << "\n";
                cout << "Choices for Imperial units" << endl;
                cout << "1. Pounds" << endl;
                cout << "2. Ounces" << endl;
                cout << "Enter your choice: ";
                cin >> user.imperialChoice;
                
                if (user.imperialChoice == 1){
                    cout << user.convertPound(user.measurement_input) << " pounds" << endl;
                }
                else if (user.imperialChoice == 2){
                    cout << user.convertOunces(user.measurement_input) << " ounces" << endl;
                }
                else{
                    cout << "Invalid" << endl;
                }
            } // This closes the 'else if (user.metricChoice == 2)'

            cout << "\n";
            cout << "Would you like to perform another conversion? (Yes / No): ";
            cin >> user.choice;
            if (user.choice == "No" || user.choice == "no"){
                isContinued = false;
            }
            else if (user.choice == "Yes" || user.choice == "yes"){
                cout << "Thank you for using our program!" << endl;
                isContinued = true;
            }
        }
    } 
  
    return 0;
}