#include <stdio.h>
#include <string>
#include<iostream>

using namespace std;

// IMPORTANT: 
//     If testing on mac/unix:    pauseVar[] = "read -p 'Press Enter to Close...' var";
//     If on windows:             pauseVar[] = "pause";
const char pauseVar[] = "pause";

const char dividerLine[] = "================================"; 

void outlinedMessage(std::string message) { // Outlines a message in dividers to make it more prominent
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

int main() {
    outlinedMessage("Pointer Illustration");
    printf("\n\nVisualize how pointers work with this neat project...");

    string a = "Hello!", *b, **c, ***d; // Each star represents 1 level of pointer (b point directly to the value, while d points to c which points to b which points to the value)
    
    // Initialize the variables to point to each other
    b = &a;
    c = &b;
    d = &c;

    // Display the illustration of pointers
    outlinedMessage("Variables");
    cout << endl << endl;
    cout << "Variable a = " << a << endl;
    cout<< "Variable b = " << b << " (Points to memory adress of 'a')" << endl;
    cout << "Variable c = " << c << " (Points to pointer 'b')" << endl;
    cout << "Variable d = " << d << " (Points to pointer 'c')" << endl;

    outlinedMessage("Memory Addresses");
    cout << endl << endl;
    cout << "a (" << &a << ") " << endl;
    cout << "b (" << &b << ") " << endl;
    cout << "c (" << &c << ") " << endl;
    cout << "d (" << &d << ") " << endl;

    outlinedMessage("Final Values");
    cout << endl << endl;
    cout << "a = "<< a << endl;
    cout << "*b = "<< *b << "            (b -> a)" << endl;
    cout << "**c = "<< **c << "           (c -> b -> a)" << endl;
    cout << "**d = " << **d << "   (d -> c -> b)" << endl;
    cout << "***d = " << ***d << "          (d -> c -> b -> a)" << endl;
    cout << endl << endl << "As you may tell, each * represents 1 level of pointer. You can specify which pointer you want to access by adding/removing a star when calling the variable. In the third final value, you can see that an incomplete path returns the coresponding pointer's pointing address.";

    printf("\n\nThat's all.");
    cout << endl << endl;

    system(pauseVar);
    return 0;
}