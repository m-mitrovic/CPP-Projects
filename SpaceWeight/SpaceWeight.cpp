#include <stdio.h>
#include <string>
#include<iostream>

using namespace std;

// Styling Variables
const char dividerLine[] = "================================"; 

void outlinedMessage(std::string message) { // Outlines a message in dividers to make it more prominent
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

// CALCULATIONS
float moonWeight(float weight) {
    return ((weight/9.81)*1.622);
}

float venusWeight(float weight) {
    return ((weight/9.81)*8.87);
}

float mercuryWeight(float weight) {
    return ((weight/9.81)*3.7);
}

float marsWeight(float weight) {
    return ((weight/9.81)*3.711);
}

float plutoWeight(float weight) {
    return (weight*0.06);
}

float jupiterWeight(float weight) {
    return ((weight/9.81)*24.79);
}

bool alreadyInputtedWeight = false ;
string message() {
    if (alreadyInputtedWeight == true) {
        return "Try again, test a different weight";
    } else {
        return "What's your weight as an Earthling";
    }
}

void menu() {
    float unit;
    float weightInput;

    cout << "\n\n" << message() << ": ";
    cin >> weightInput;
    alreadyInputtedWeight = true; // Update value so message can change next time
    cout << endl << "Moon Weight: " << moonWeight(weightInput) << endl;
    cout << "Venus Weight: " << venusWeight(weightInput) << endl;
    cout << "Mercury Weight: " << mercuryWeight(weightInput) << endl;
    cout << "Mars Weight: " << marsWeight(weightInput) << endl;
    cout << "Pluto Weight: " << plutoWeight(weightInput) << endl;
    cout << "\n" << "BONUS..." << endl;
    cout << "Jupiter Weight: " << jupiterWeight(weightInput) << endl;

    menu(); // Ask again
}

int main() {
    outlinedMessage("Space Weight");
    printf("\n\nCalculate how much you'd weight on the moon, venus, mercury, mars, and pluto!");
    
    menu();

	return 0; // End the program
}