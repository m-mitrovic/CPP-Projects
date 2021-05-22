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

class Project { // Project class - Contains project name, description, and path     
  public:             
    string name;
    string folderName;
    string exePath;

    Project(string projectName, string projectFolder, string projectPath) { // Constructor with parameters
      name = projectName;
      folderName = projectFolder;
      exePath = projectPath;
    }
};

Project myProjects[] = {
    ::Project("Name Repeat", "RepeatNameC", "RepeatNameC/RepeatName"),
    ::Project("Calculator", "Calculator", "Calculator/Calculator"),
    ::Project("Shape Calculator", "ShapeCalculator", "ShapeCalculator/Calculator"),
    ::Project("Falling Binary Illusion", "FallingBinary", "FallingBinary/FallingBinary"),
    ::Project("Temperature Conversion", "TempConverter", "TempConverter/TempConverter"),
    ::Project("Item Search", "ItemSearch", "ItemSearch/ItemSearch"),
    ::Project("Space Weight", "SpaceWeight", "SpaceWeight/SpaceWeight"),
    ::Project("Pre-set (Encrypted) Password", "EncryptedPassword", "EncryptedPassword/EncryptedPassword"),
    ::Project("Pointer Illustration", "PointerIllustration", "PointerIllustration/PointerIllustration"),
    ::Project("String Counter", "StringCounter", "StringCounter/StringCounter"),
};

void outlinedMessage(std::string message) { // Outlines a message in dividers to make it more prominent
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

// Lists all projects in myProjects array
void listProjects() {
    printf("\n\n");
    for (unsigned int a = 0; a < (sizeof(myProjects) / sizeof(myProjects[0])); a++) { // Loop through items
        cout << (a + 1) << ")  " << myProjects[a].name << "  -  Folder: " << myProjects[a].folderName << endl;
    }
}

void openExe(string path) {
    string finalPath = path+" application.ini";
    const char * final = finalPath.c_str();
    int result = system(final);
}

void menu() {
    int input;

    outlinedMessage("Welcome!");
    printf("\n\nHere's all of the C++ projects I've completed in one menu system. I've learned a lot through the proccess and refined my code as I progressed through each challenge. I'd recommend viewing the code (.cpp files) of the projects because I left some informative comments explaining how the code functions most efficiently. I hope you enjoy!");
    printf("\n\nNOTE: These projects are compiled for Windows. If the exe is corrupt or not working, please try launching the program from the .cpp files.");
   
    listProjects();

    printf("\n\nWhich project would you like to launch?: ");
   cin >> input;

   switch (input) {
       case 1:
        openExe(myProjects[input-1].exePath);
       case 2:
        openExe(myProjects[input-1].exePath);
       case 3:
        openExe(myProjects[input-1].exePath);
       case 4:
        openExe(myProjects[input-1].exePath);
       case 5:
        openExe(myProjects[input-1].exePath);
       case 6:
        openExe(myProjects[input-1].exePath);
       case 7:
        openExe(myProjects[input-1].exePath);
       case 8:
        openExe(myProjects[input-1].exePath);
       case 9:
        openExe(myProjects[input-1].exePath);
       case 10:
        openExe(myProjects[input-1].exePath);
   }
    //int result = system("Calculator/Calculator application.ini");

}

int main() {
    menu();

	return 0; // End the program
}