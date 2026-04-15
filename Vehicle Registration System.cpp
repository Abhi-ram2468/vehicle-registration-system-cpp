#include <iostream>
#include <string>

using namespace std;

// Declare global arrays to store vehicle information
const int MAX_VEHICLES = 100;       // Max number of vehicles we can register
string regNumbers[MAX_VEHICLES];    // Array to store registration numbers
string ownerNames[MAX_VEHICLES];    // Array to store owner names
string vehicleTypes[MAX_VEHICLES];  // Array to store vehicle types (Car, Bike, etc.)
string brands[MAX_VEHICLES];        // Array to store brands
string models[MAX_VEHICLES];        // Array to store models
int years[MAX_VEHICLES];            // Array to store years of manufacture
string colors[MAX_VEHICLES];        // Array to store colors
int vehicleCount = 0;               // Counter to track the number of registered vehicles

// Function to register a new vehicle
void registerVehicle() {
    if (vehicleCount >= MAX_VEHICLES) {
        cout << "Cannot register more vehicles. Maximum limit reached." << endl;
        return;
    }

    string regNumber, ownerName, vehicleType, brand, model, color;
    int year;

    // Get user input for the vehicle's details
    cout << "Enter Registration Number: ";
    cin >> regNumber;
    cout << "Enter Owner Name: ";
    cin.ignore();  // To clear the newline left by previous cin
    getline(cin, ownerName);
    cout << "Enter Vehicle Type (Car, Bike, etc.): ";
    cin >> vehicleType;
    cout << "Enter Brand: ";
    cin >> brand;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Year of Manufacture: ";
    cin >> year;
    cout << "Enter Color: ";
    cin >> color;

    // Store the vehicle details in the arrays
    regNumbers[vehicleCount] = regNumber;
    ownerNames[vehicleCount] = ownerName;
    vehicleTypes[vehicleCount] = vehicleType;
    brands[vehicleCount] = brand;
    models[vehicleCount] = model;
    years[vehicleCount] = year;
    colors[vehicleCount] = color;

    vehicleCount++;  // Increment the vehicle count
    cout << "Vehicle registered successfully!" << endl;
}

// Function to search for a vehicle by its registration number
void searchByRegNumber(const string& regNumber) {
    bool found = false;

    // Search through the arrays of vehicles
    for (int i = 0; i < vehicleCount; ++i) {
        if (regNumbers[i] == regNumber) {
            // Display the vehicle details
            cout << "Registration Number: " << regNumbers[i] << endl;
            cout << "Owner Name: " << ownerNames[i] << endl;
            cout << "Vehicle Type: " << vehicleTypes[i] << endl;
            cout << "Brand: " << brands[i] << endl;
            cout << "Model: " << models[i] << endl;
            cout << "Year: " << years[i] << endl;
            cout << "Color: " << colors[i] << endl;
            cout << "-----------------------------" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No vehicle found with that registration number." << endl;
    }
}

// Function to display all registered vehicles
void displayAllVehicles() {
    if (vehicleCount == 0) {
        cout << "No vehicles registered." << endl;
    } else {
        for (int i = 0; i < vehicleCount; ++i) {
            // Display vehicle details
            cout << "Registration Number: " << regNumbers[i] << endl;
            cout << "Owner Name: " << ownerNames[i] << endl;
            cout << "Vehicle Type: " << vehicleTypes[i] << endl;
            cout << "Brand: " << brands[i] << endl;
            cout << "Model: " << models[i] << endl;
            cout << "Year: " << years[i] << endl;
            cout << "Color: " << colors[i] << endl;
            cout << "-----------------------------" << endl;
        }
    }
}

// Main function
int main() {
    int choice;

    while (true) {
        // Display the menu
        cout << "Vehicle Registration System" << endl;
        cout << "1. Register a Vehicle" << endl;
        cout << "2. Search for a Vehicle by Registration Number" << endl;
        cout << "3. Display All Registered Vehicles" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerVehicle();
                break;
            case 2: {
                string regNumber;
                cout << "Enter Registration Number to search: ";
                cin >> regNumber;
                searchByRegNumber(regNumber);
                break;
            }
            case 3:
                displayAllVehicles();
                break;
            case 4:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
