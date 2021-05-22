#include <stdio.h>
#include <string>
#include <cmath>

int shapeSelected = 1;

// Generic input value variables (each shape uses them differently - for example shpere may use inputValue1 for radius)
float inputValue1 = 0;
float inputValue2 = 0;
float inputValue3 = 0;

// Math Definitions
float pi = 3.14159265;

// IMPORTANT: 
//     If testing on mac/unix:    pauseVar[] = "read -p '  Press Enter to Refresh...' var";
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

void printAnswer(float area, float circumference) { // Print final volume and surface area calculations
    std::string finalOutput = format("Volume = %.8g", area) + format("   -   Surface Area = %.8g", circumference);
    outlinedMessage(finalOutput);
    std::system(pauseVar);
}

// SHAPE: Sphere
float sphereVolume() { // Calculates volume of shpere from input variables
    float radius = inputValue1;
    return ((4.0/3)*pi*pow(radius, 3)); // Formula for volume
}

float shpereSurfaceArea() { // Calculates surface area
    float radius = inputValue1;
    return (4*pi*pow(radius, 2));
}

void sphereInput() { // Shape-specific message to gather inputValues needed for calculation
    printf("\n\nSphere radius: ");
    scanf(" %f", &inputValue1);
    printAnswer(sphereVolume(), shpereSurfaceArea());
}

// SHAPE: Cylinder
float cylinderVolume() {
    float radius = inputValue1;
    float height = inputValue2;
    return (pi*pow(radius, 2)*height);
}

float cylinderSurfaceArea() {
    float radius = inputValue1;
    float height = inputValue2;
    return (2*pi*radius*height+2*pi*pow(radius, 2));
}

void cylinderInput() {
    printf("\n\nCylinder radius: ");
    scanf(" %f", &inputValue1);
    printf("\n\nCylinder height: ");
    scanf(" %f", &inputValue2);
    printAnswer(cylinderVolume(), cylinderSurfaceArea());
}

// SHAPE: Cone
float coneVolume() {
    float radius = inputValue1;
    float height = inputValue2;
    return (pi*pow(radius, 2)*(height/3));
}

float coneSurfaceArea() {
    float radius = inputValue1;
    float height = inputValue2;
    return (pi*radius*(radius+sqrt((pow(height, 2)+pow(radius, 2)))));
}

void coneInput() { 
    printf("\n\nCone radius: ");
    scanf(" %f", &inputValue1);
    printf("\nCone height: ");
    scanf(" %f", &inputValue2);
    printAnswer(coneVolume(), coneSurfaceArea());
}

// SHAPE: Cuboid
float cuboidVolume() {
    float length = inputValue1;
    float width = inputValue2;
    float height = inputValue3;
    return (length*width*height);
}

float cuboidSurfaceArea() {
    float length = inputValue1;
    float width = inputValue2;
    float height = inputValue3;
    return ((2*length*width)+(2*length*height)+(2*height*width));
}

void cuboidInput() { 
    printf("\n\nCuboid length: ");
    scanf(" %f", &inputValue1);
    printf("\nCuboid width: ");
    scanf(" %f", &inputValue2);
    printf("\nCuboid height: ");
    scanf(" %f", &inputValue3);
    printAnswer(cuboidVolume(), cuboidSurfaceArea());
}

// SHAPE: Triangular Prism
float triangularVolume() {
    float height = inputValue1;
    float base = inputValue2;
    float length = inputValue3;
    return ((0.5)*height*base*length);
}

float triangularSurfaceArea() {
    float height = inputValue1;
    float base = inputValue2;
    float length = inputValue3;
    return ((base*height)+(3*length*base));
}

void triangularInput() {  
    printf("\n\nHeight of triangular base: ");
    scanf(" %f", &inputValue1);
    printf("\nTriangular base length: ");
    scanf(" %f", &inputValue2);
    printf("\nLength of shape: ");
    scanf(" %f", &inputValue3);
    printAnswer(triangularVolume(), triangularSurfaceArea());
}

// SHAPE: Square-Based Pyramid
float sbPyramidVolume() {
    float base = inputValue1;
    float height = inputValue2;
    return (pow(base, 2)*(height/3));
}

float sbPyramidSurfaceArea() {
    float base = inputValue1;
    float height = inputValue2;
    return (pow(base, 2)+2*base*(sqrt(((pow(base, 2)/4)+pow(height, 2)))));
}

void sbPyramidInput() {  
    printf("\n\nPyramid base edge length: ");
    scanf(" %f", &inputValue1);
    printf("\nPyramid height: ");
    scanf(" %f", &inputValue2);
    printAnswer(sbPyramidVolume(), sbPyramidSurfaceArea());
}

void calculatorMenu() { // Initialize calculator menu (when program started/reset)
    outlinedMessage("Shape Calculator");

    printf("\n\n\n1) Sphere");
    printf("\n2) Cylinder");
    printf("\n3) Cone");
    printf("\n4) Cuboid/Rectangular Prism");
    printf("\n5) Triangular Prism");
    printf("\n6) Square-Based Pyramid");
    printf("\n\nSelect which calculator you would like: ");
    scanf(" %i", &shapeSelected);

    switch (shapeSelected) { // Show corresponding menu with term inputted, or alert invalid range error
        case 1:
            sphereInput();
            calculatorMenu();
        case 2:
            cylinderInput();
            calculatorMenu();
        case 3:
            coneInput();
            calculatorMenu();
        case 4:
            cuboidInput();
            calculatorMenu();
        case 5:
            triangularInput();
            calculatorMenu();
        case 6:
            sbPyramidInput();
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