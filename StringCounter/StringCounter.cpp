#include <stdio.h>
#include <string>
#include<iostream>
#include <map>

using namespace std;

string stringInput;
map<char, int> stringOccurancesMap;

// IMPORTANT: 
//     If testing on mac/unix:    pauseVar[] = "read -p 'Press Enter to Refresh...' var";
//     If on windows:             pauseVar[] = "pause";
const char pauseVar[] = "pause";

// Styling Variables
const char dividerLine[] = "================================"; 

// Outlines a message in dividers to make it more prominent
void outlinedMessage(std::string message) { 
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

// Loop through each character & save all character occurances (backend)
void analyzeCharacters() { 
    for (std::size_t x = 0, length = stringInput.length(); x != length; ++x) {
        char character = toupper(stringInput.at(x)); // Make character uppercase so program isnt case sensitive
        if (stringOccurancesMap.count(character) == 1) { // Item exists in dict
            // Add 1 character occurance value
            int charCount = stringOccurancesMap[character] + 1;
            stringOccurancesMap[character] = charCount;
            //cout << "\nCharacter " << character << " exists - " << stringOccurancesMap[character] << " - " << charCount;
        } else {
            stringOccurancesMap.insert(pair<char, int>(character, 1));
           // cout << "\nCharacter " << character << " doesn't exist";
        }
    }
}

// Print the breakdown for each letter
void characterOccuranceMessage() { 
    printf("\n\n\n");
    cout << "Total string length: " << stringInput.length() << "\n";
    map<char, int>::iterator it = stringOccurancesMap.begin();
    // Loop through all unique character occurances
    while (it != stringOccurancesMap.end()) { 
        char key = it->first;
        int value = it->second;
        int length = stringInput.length();
        double percent = (double)it->second / length * 100;
        cout << "\n" << key << " - " << "Occurances: " << value << " (" << percent << "%)";

        it++;
    }
    printf("\n\n\n");
}

// Structures the breakdown and performs character analysis
void stringBreakdown() {
    outlinedMessage("The Breakdown");
    cout << "\n\n" << "Breakdown for \"" << stringInput << "\"";
    analyzeCharacters();
    characterOccuranceMessage();
}

// Message to recieve input string
void inputString() {
    outlinedMessage("String Counter");
    printf("\n\nSee the length of your inputted text, the letter similarities, and other interesting things regarding the string.");

    cout << "\n\nYour string: ";
    cin >> stringInput;

    stringBreakdown();

    // Clear previous session & reload program
    system(pauseVar); 
    stringInput = "";
    stringOccurancesMap.clear();
    inputString();
}

int main() {
    inputString();
    return 0;
}