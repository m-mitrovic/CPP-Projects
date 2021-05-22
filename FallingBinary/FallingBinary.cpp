#include<iostream>
#include<string>
#include<thread>
#include<chrono>
  
const int intensity = 2; // Affects how many characters move per line. Eg: 1 = low intensity, 20 = high binary falling intensity
const int canvasWidth = 55; // Width of canvas (in characters)
  
int main() {
    // Declare starting variables
    int x = 0;
    int i = 0;
  
    srand(time(NULL)); // Initiates random values when program runs
  
    bool characterMoves[canvasWidth] = {0}; // Decides to print or not to print character in the following line
    const std::string ch = "01"; // Picks from either 0 or 1 for binary
    const int l = ch.size();
  
    // Infinite loop
    while (true) {
        for (i=0;i<canvasWidth;i+=2) { // Loop over the canvasWidth
            if (characterMoves[i]) { // If this character moves in this location (characterMoves[i] == 1) then print the character to give it a falling illusion
                std::cout << ch[rand() % l] << " ";
            } else { // Else, print a blank space
                std::cout<<"  ";
            }
        }
  
        for (i=0; i!=intensity; ++i) { // Decides which characters will move in the next line randomly for the falling illusion
            x = rand() % canvasWidth;
            characterMoves[x] = !characterMoves[x];
        }
  
        std::cout << std::endl; // Make a new line (same as printf("\n"))
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Delay converted from seconds to miliseconds for use in sleep_for function

        // After the delay, this block is repeated. It continues to repeat indefinetly.
    }
    return 0;
}