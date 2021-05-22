#include <stdio.h>
#include <string>
#include<iostream>

using namespace std;

// Styling Variables
const char dividerLine[] = "================================"; 

class Item { // Item class - Configured for cars as an example      
  public:             
    int id; // ID asociated with car
    string name;  // Name of car
    double mpg; // Miles per gallon
    int hp; // Gross horse power
    string tm; // Transmission (automatic or manual)
    double wt; // Weight in tons
    double qsec; // Quarter mile time in seconds
    Item(int carId, string carName, double milesPerGallon, int horsePower, int transmission, double weight, double quarterMile) { // Constructor with parameters
      id = carId;
      name = carName;
      mpg = milesPerGallon;
      hp = horsePower;
      if (transmission == 0) { // Transmission (0 - automatic, 1 - manual)
            tm = "Automatic";
        } else {
            tm = "Manual";
        }
        wt = weight;
        qsec = quarterMile;
    }
};

// Array storing all car objects
// I got this list by finding a car database online (.csv) & made a python script to scarpe that csv file
// It then returned this array which lets me automate the tedious task of inputting data
// The .py file & CSV are also attached to this folder
Item items[] = {
	::Item(100, "Mazda RX4", 21, 110, 1, 2.62, 16.46),
	::Item(101, "Mazda RX4 Wag", 21, 110, 1, 2.875, 17.02),
	::Item(102, "Datsun 710", 22.8, 93, 1, 2.32, 18.61),
	::Item(103, "Hornet 4 Drive", 21.4, 110, 0, 3.215, 19.44),
	::Item(104, "Hornet Sportabout", 18.7, 175, 0, 3.44, 17.02),
	::Item(105, "Valiant", 18.1, 105, 0, 3.46, 20.22),
	::Item(106, "Duster 360", 14.3, 245, 0, 3.57, 15.84),
	::Item(107, "Merc 240D", 24.4, 62, 0, 3.19, 20),
	::Item(108, "Merc 230", 22.8, 95, 0, 3.15, 22.9),
	::Item(109, "Merc 280", 19.2, 123, 0, 3.44, 18.3),
	::Item(110, "Merc 280C", 17.8, 123, 0, 3.44, 18.9),
	::Item(111, "Merc 450SE", 16.4, 180, 0, 4.07, 17.4),
	::Item(112, "Merc 450SL", 17.3, 180, 0, 3.73, 17.6),
	::Item(113, "Merc 450SLC", 15.2, 180, 0, 3.78, 18),
	::Item(114, "Cadillac Fleetwood", 10.4, 205, 0, 5.25, 17.98),
	::Item(115, "Lincoln Continental", 10.4, 215, 0, 5.424, 17.82),
	::Item(116, "Chrysler Imperial", 14.7, 230, 0, 5.345, 17.42),
	::Item(117, "Fiat 128", 32.4, 66, 1, 2.2, 19.47),
	::Item(118, "Honda Civic", 30.4, 52, 1, 1.615, 18.52),
	::Item(119, "Toyota Corolla", 33.9, 65, 1, 1.835, 19.9),
	::Item(120, "Toyota Corona", 21.5, 97, 0, 2.465, 20.01),
	::Item(121, "Dodge Challenger", 15.5, 150, 0, 3.52, 16.87),
	::Item(122, "AMC Javelin", 15.2, 150, 0, 3.435, 17.3),
	::Item(123, "Camaro Z28", 13.3, 245, 0, 3.84, 15.41),
	::Item(124, "Pontiac Firebird", 19.2, 175, 0, 3.845, 17.05),
	::Item(125, "Fiat X1-9", 27.3, 66, 1, 1.935, 18.9),
	::Item(126, "Porsche 914-2", 26, 91, 1, 2.14, 16.7),
	::Item(127, "Lotus Europa", 30.4, 113, 1, 1.513, 16.9),
	::Item(128, "Ford Pantera L", 15.8, 264, 1, 3.17, 14.5),
	::Item(129, "Ferrari Dino", 19.7, 175, 1, 2.77, 15.5),
	::Item(130, "Maserati Bora", 15, 335, 1, 3.57, 14.6),
	::Item(131, "Volvo 142E", 21.4, 109, 1, 2.78, 18.6),
};

void outlinedMessage(std::string message) { // Outlines a message in dividers to make it more prominent
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

// Unified spacer size (user-facing)
void spacer() { 
    printf("\n\n");
}

// Lists all items in items array
void listItems() {
    spacer();
    for (unsigned int a = 0; a < (sizeof(items) / sizeof(items[0])); a++) { // Loop through items
        cout << "Car: " << items[a].name << "  -  ID: " << items[a].id << endl;
    }
}

// Prints description of item (user-facing)
void itemDescription(Item item) {
    outlinedMessage(item.name);
    spacer();
    cout << "Car: " << item.name << "  -  ID: " << item.id << "\n\n";
    cout << "Description of vehicle: " << endl;
    cout << item.mpg << " Miles Per Gallon" << endl;
    cout << item.hp << " Gross Horsepower" << endl;
    cout << item.tm << " Transmission" << endl;
    cout << ((item.wt*1000)/2.205) << " Kilograms" << endl;
    cout << item.qsec << " Seconds Quarter Mile Time" << endl;
}

// Searches item by id
void searchItemId(string id) {
    Item itemMatched = ::Item(0, "Not Found", 0, 0, 0, 0, 0);
    for (unsigned int a = 0; a < (sizeof(items) / sizeof(items[0])); a++) { // Loop through items
       if (id.find(to_string(items[a].id)) != string::npos) { // IDs match
            cout << "IDS match - " << items[a].name << endl;
            itemMatched = items[a];
            break;
       }
    }
    
    if (itemMatched.id == 0) { // Item not found
        spacer();
        cout << "Item with ID " << id << " not found.";
    } else {
        itemDescription(itemMatched);
    }
}

// Search bar (user-facing)
void menu() {
    string searchValue;
    printf("\n\nTIP: List the cars and their corresponding IDs by searching \"list\"");
    printf("\n\nSearch cars by ID: ");
    cin >> searchValue;

    if (searchValue == "list") { // List the array
        listItems();
    } else { // Search ID
        searchItemId(searchValue);
    }

    menu(); // Loops the program and allows re-searching infinite times
}

int main() {
    outlinedMessage("Item Search");
    printf("\n\nThis demo program that lets you test an item search system which allows users to quickly search through different cars. This program can be easily populated with real products for a business and can act as an inventory check, local product database, along with many other real world uses. For this demo, you'll be able to get a description of different cars and compare their miles per gallon, speed, and other important factors.");
    
    menu();

	return 0; // End the program
}