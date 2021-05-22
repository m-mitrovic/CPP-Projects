#include <stdio.h>
#include <string>

std::string password;
std::string privateKey;
std::string publicKey = "$tech%^class*ICU!@"; // Public key ads more complexity to the passwords encryption

// Styling Variables
char dividerLine[] = "================================"; 

std::string encrypt(std::string encText) { // Custom encryption of password so that the plain text password cannot be accessed
    const int ROT13 = 13, ROT7 = 7;
    int key = ROT13;
	encText = encText + privateKey + publicKey;
	for (size_t i = 0; i < encText.size(); i++)
	{
		encText[i] = encText[i] + key;

		if ((i + 1) % 5 == 0)
		{
			if (key == ROT7)
				key = ROT13;
			else
				key = ROT7;
		}
	}
    return encText;
}

// Genereates random key in session to be used as a salt for storing the encrypted password (makes decoding the password exponentially more difficult)
std::string generatePrivateKey() {
    std::string str = "!@#$%^&*()~{}_+-=:<>?0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // Selects random character from this string
    std::string newstr;
    int pos;
    int stringLength = 8;
    while(newstr.size() != stringLength) {
        pos = ((rand() % (str.size()-1)));
        newstr += str.substr(pos, 1);
    }
   return newstr;
}

void outlinedMessage(std::string message) { // Outlines a message in dividers to make it more prominent
    printf("\n\n%s", dividerLine);
    printf("\n  %s\n%s", message.c_str(), dividerLine);
}

void createPassword() {
    char passwordRaw[] = "";
    printf("\n\nPlease create your secure password: ");
	scanf(" %s", passwordRaw);
    privateKey = generatePrivateKey();
    password = encrypt(passwordRaw);
    printf("\nPassword encrypted & saved!\n");
}

void loginPrompt(); // Declare function ahead so it can be used

void unlockedMenu() {
    // Explaination of how it was done
    outlinedMessage("You're In!");
    printf("\n\nCongrats, the password you originally set matches with the password that you just inputted. The password is encrypted using a custom (secret) encryption protocol, and a mix of private and public keys which makes it exponentially more complex for a bad actor to decrypt.");
    printf("\n\nYour plain text password is inaccessible to anyone...including myself. What I do to ensure that you inputted the correct password is encrypt the password you login and compare it to the encrypted password stored. This ensures that even if a bad actor got a hold of the 'password' var, all they would see is: \n\n%s", password.c_str());
    printf("\n\n^ They cannot really do much with that. This is a very similar system to what Facebook, Instagram, Amazon, and all other login providers use.");

    // Ending menu
    printf("\n\nThat's all. Made by Mihajlo M.");
    printf("\n\n   1) Logout");
    printf("\n\n   2) Exit");
    printf("\n\nSelect an option: ");
    int optionSelected = 1;
    scanf(" %d", &optionSelected);
    switch (optionSelected) {
        case 2: 
            printf("\n\n"); // Nothing...end the program
            exit(0);
        default:
            loginPrompt();
    }
}

void passwordFailed() {
    printf("\n\nPassword does not match. Please try again.");
    loginPrompt();
}

void loginPrompt() {
    outlinedMessage("Login");
    printf("\n\nEnter your password: ");
    char passwordRaw[] = "";
    scanf(" %s", passwordRaw);
    std::string encryptedPassword = encrypt(passwordRaw);
    if (encryptedPassword == password) { // Passwords match, user successfully entered password
        unlockedMenu();
    } else {
        passwordFailed();
    }
}

int main() {
    outlinedMessage("Encrypted Password");

    createPassword();
    loginPrompt();

	return 0; // End the program
}