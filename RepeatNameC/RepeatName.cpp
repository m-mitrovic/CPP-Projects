#include <stdio.h>

int main() {
	char name[20]; // Cap the name to 20 characters
	int repeatCount=0;
	int i=0;
	
    printf("\nRepeat Name \n\nRepeat your name as many times as you please!\n");
	printf("\nWhich name would you like to repeat?: ");
	scanf(" %s", name);
	
	printf("\nHow many times would you like to repeat %s?: ", name);
	scanf(" %d", &repeatCount);
	
	while (i < repeatCount)
	{ // Loop through and print name for range 0...(repeatCount-1)
		i++;
		printf("\n%s (%d)", name, i);
	}
	
	printf("\n\n------------------\nAll done! Printed %s %d times!\n\n", name, repeatCount); // Ending message
	return 0; // End the program
}
