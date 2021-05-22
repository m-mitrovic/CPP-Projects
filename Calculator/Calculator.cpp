#include <stdio.h>
#include <string>
#include <cmath>

int menuSelected = 1;
int operationSelected = 1;
float firstNumber = 0;
float secondNumber = 0;

// Math Terms
float pi = 3.14159265;

// IMPORTANT: 
//     If testing on mac/unix:    pauseVar[] = "read -p 'Press Enter to Refresh...' var";
//     If on windows:             pauseVar[] = "pause";
char pauseVar[] = "pause";

// Styling Variables
char dividerLine[] = "================================"; 

void outlinedMessage(std::string message) { // Outlines a message in dividers to make it more prominent
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

void displayError(std::string message) { // Displays custom error message
    printf("\n\n%s", dividerLine);
    printf("\n  ERROR: %s\n  Calculator has been reset.\n%s", message.c_str(), dividerLine);
}

inline std::string format(const char* fmt, ...){ // Format string to remove trailing zeros (used in answer to remove unnessisary 0s)
    int size = 512;
    char* buffer = 0;
    buffer = new char[size];
    va_list vl;
    va_start(vl, fmt);
    int nsize = vsnprintf(buffer, size, fmt, vl);
    if(size <= nsize){
        delete[] buffer;
        buffer = 0;
        buffer = new char[nsize+1];
        nsize = vsnprintf(buffer, size, fmt, vl);
    }
    std::string ret(buffer);
    va_end(vl);
    delete[] buffer;
    return ret;
}

float basicCalculation() { // Returns the calculation (+ - / *) depending on which operation selected
    switch (operationSelected) {
        case 1:
            return (firstNumber + secondNumber);
        case 2:
            return (firstNumber - secondNumber);
        case 4:
            return (firstNumber / secondNumber);
        default:
            return (firstNumber * secondNumber);
    }
}

float trigCalculation() { // Returns final answers for trig operations
    switch (operationSelected) {
        case 1:
            return sin(firstNumber*pi/180);
        case 2:
            return cos(firstNumber*pi/180);
        case 3:
            return tan(firstNumber*pi/180);
        case 4:
            return (asin(firstNumber)*180/pi);
        case 5:
            return (acos(firstNumber)*180/pi);
        case 6:
            return (atan(firstNumber)*180/pi);
        default:
            return sin(firstNumber*pi/180);
    }
}

float exponentCalculation() { // Returns exponent/root answer
    switch (operationSelected) {
        case 1: // Exponent
            return pow(secondNumber, firstNumber);
        case 2: // Radicand
            return pow(secondNumber, (1/firstNumber));
        default: // Default to exponent
            return pow(secondNumber, firstNumber);
    }
}

std::string calculation() { // Formats and returns the answer. Eg "= 23.23"
    float finalNumber = basicCalculation(); // Default to basic calculation
    if (menuSelected == 2) {
        finalNumber = trigCalculation();
    } else if (menuSelected == 3) {
        finalNumber = exponentCalculation();
    }

    // Format string for display and show math error if answer is nil or undefined if answer is infinite
    if (std::isnan(finalNumber)) {
        return " = Math Error";
    } else if (!std::isnormal(finalNumber)) {
        return " = Undefined";
    } else {
        return format(" = %.8g", finalNumber);
    }
}

std::string basicOperationSymbol() { // Returns the math symbol for the selected operation
    switch (operationSelected) {
        case 1:
            return " + ";
        case 2:
            return " - ";
        case 4:
            return " ÷ ";
        default:
            return " × ";
    }
}

void basicCalculator() { // Performs addition, subtraction, multiplication and division
    outlinedMessage("Basic Calculator");
    printf("\n\n\n1) Addition");
    printf("\n\n2) Subtraction");
    printf("\n\n3) Multiplication");
    printf("\n\n4) Division");
    printf("\n\nSelect which operation you would like to perform: ");
    scanf(" %i", &operationSelected);

    printf("\n\nFirst number: ");
    scanf(" %f", &firstNumber);

    printf("\nSecond number: ");
    scanf(" %f", &secondNumber);

    // Structure final equals message
    std::string finalOutup = format("%.8g", firstNumber) + basicOperationSymbol() + format("%.8g", secondNumber) + format(" = %.8g", basicCalculation());
    outlinedMessage(finalOutup);
    std::system(pauseVar);
}

std::string trigFunctionName() { // Returns user facing name for operation selected
    switch (operationSelected) {
        case 1:
            return "Sine";
        case 2:
            return "Cos";
        case 3:
            return "Tangent";
        case 4:
            return "Sine Inverse";
        case 5:
            return "Cos Inverse";
        case 6:
            return "Tangent Inverse";
        default:
            return "Sine";
    }
}

void trigCalculator() { // Performs sin, cos, tan, etc.
    outlinedMessage("Trigonometric Calculator");
    printf("\n\n\n1) Sine");
    printf("\n\n2) Cos");
    printf("\n\n3) Tangent");
    printf("\n\n4) Sine Inverse");
    printf("\n\n5) Cos Inverse");
    printf("\n\n6) Tangent Inverse");
    printf("\n\nSelect which operation you would like to perform: ");
    scanf(" %i", &operationSelected);

    printf("\n\n%s of how many degrees?: ", trigFunctionName().c_str());
    scanf(" %f", &firstNumber);

    // Structure final equals message
    std::string finalOutup =  trigFunctionName() + " of " + format("%.8g", firstNumber) + " degrees" + calculation();
    outlinedMessage(finalOutup);
    std::system(pauseVar);
}

std::string exponentInitialQuestion() { // Get coresponding question for the number to insert
    if (operationSelected == 2) { // Square
        return "Radical index (2 for square root): ";
    } else {
        return "Exponent (2 for squaring): ";
    }
}

std::string exponentSecondaryQuestion() { // Get coresponding question for the 2nd number to insert
    if (operationSelected == 2) {
        return "Radicand: ";
    } else {
        return "Base: ";
    }
}

void exponentCalculator() { // Exponents & radicals
    outlinedMessage("Exponent/Root Calculator");
    printf("\n\n\n1) Exponent");
    printf("\n\n2) Radical");
    printf("\n\nSelect which operation you would like to perform: ");
    scanf(" %i", &operationSelected);

    printf("\n\n%s", exponentInitialQuestion().c_str());
    scanf(" %f", &firstNumber);

    printf("\n\n%s", exponentSecondaryQuestion().c_str());
    scanf(" %f", &secondNumber);

    // Structure final equals message
    std::string finalOutup =  calculation();
    outlinedMessage(finalOutup);
    std::system(pauseVar);
}

void calculatorMenu() { // Initialize calculator menu (when program started/reset)
    outlinedMessage("Calculator");

    printf("\n\n\n1) Addition, Subtraction, Multiplication, & Division");
    printf("\n2) Trigonometric Operations");
    printf("\n3) Exponents & Roots");
    printf("\n\nSelect which calculator you would like: ");
    scanf(" %i", &menuSelected);

    switch (menuSelected) { // Show corresponding menu with term inputted, or alert of error
        case 1:
            basicCalculator();
            calculatorMenu();
        case 2:
            trigCalculator();
            calculatorMenu();
        case 3:
            exponentCalculator();
            calculatorMenu();
        default: // Handle invalid range
            displayError("Invalid range.");
            calculatorMenu();
    }
}

int main() {
    calculatorMenu(); // Initialize the program
    return 0;
}