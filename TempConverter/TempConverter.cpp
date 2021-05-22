#include <stdio.h>
#include <string>
#include<iostream>

using namespace std;

// Styling Variables
const char dividerLine[] = "================================"; 

// IMPORTANT: 
//     If testing on mac/unix:    pauseVar[] = "read -p 'Press Enter to Refresh...' var";
//     If on windows:             pauseVar[] = "pause";
const char pauseVar[] = "pause";

void outlinedMessage(std::string message) { // Outlines a message in dividers to make it more prominent
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

// INPUTS CELCUIS AND CONVERTS TO RESPECTIVE TEMP
float toFahren(float celcius) {
    return ((celcius*(9.0/5))+32);
}

float toRankine(float celcius) {
    return (celcius*(9.0/5)+491.67);
}

float toKelvin(float celcius) {
    return (celcius+273.15);
}

float convertTempToCelcius(int unit, float temp) {
    if (unit == 2) { // Far
        return ((temp-32)*(5.0/9));
    } else if (unit == 3) { // Ran
        return ((temp-491.67)*(5.0/9));
    } else if (unit == 4) { // Kel
        return (temp-273.15);
    } else { // Cel
        return temp;
    }
}

void outputConversions(float celcius) {
    printf("\n\n");
    cout << "Celcius: " << celcius << endl;
    cout << "Fahrenheit: " << toFahren(celcius) << endl;
    cout << "Rankine: " << toRankine(celcius) << endl;
    cout << "Kelvin: " << toKelvin(celcius) << endl;
    printf("\n\n");
    system(pauseVar);
}

void menu() {
    int temperatureUnit;
    printf("\n\n  1. Celcius\n\n  2. Fahrenheit\n\n  3. Rankin\n\n  4. Kelvin");
    cout << "\n\nTemperature unit: ";
    cin >> temperatureUnit;

    float inputTemp;
    cout << "\nInput temperature: ";
    cin >> inputTemp;

    // Convert the temp to celcius to be further converted into the other temperatures
    float celciusTemp = convertTempToCelcius(temperatureUnit, inputTemp); 
    outputConversions(celciusTemp);

    menu(); // Reload program
}

int main() {
    outlinedMessage("Temperature Converter");
    printf("\n\nInput a temperature and convert it to Fahrenheit, Celsius, Rankin & Kelvin.");
    
    menu();

	return 0; // End the program
}