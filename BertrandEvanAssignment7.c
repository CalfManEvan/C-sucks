/*
Evan Bertrand
CS2060-002
Assignment 7
Due 11/23/2021

For this program, we need to ask a user for pet names and ages and store them in a
linked list alphabetically. The program will then display those pets first in
alphabetical order then in order of age. we will also ask the user if they want to
remove pets from the list until they say no or until the list is empty. We will display
the remaining pets in the list if there are any.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//defines max length of name is 20 (name + null character)
#define NAME_LEN 51

//defines max age is double digits (reading age in as string)
#define AGE 3

//defines the max number of names to be entered as a 4 digit number
#define NUM_NAMES 5

void enterPetName(char name[NAME_LEN]);
int enterPetAge();
void entryMode(char nameArray[NAME_LEN], int age, int numNames, Pet* headPtr);

typedef struct Pet_s {

	char name[NAME_LEN];
	int age;
	struct Pet_s* nextPetPtr;

} Pet;

int main(void) {

	char nameArray[NAME_LEN] = { 0 };
	char numNames[NUM_NAMES] = { 0 };

	enterPetName(nameArray);

	//int age = enterPetAge();

	printf("%s\n", "How many names are to be entered?");
	fgets(numNames, NUM_NAMES, stdin);



	return 0;

}

//this function asks the user to enter their pet's name
void enterPetName(char name[NAME_LEN]) {

	printf("%s", "Please enter your pet's name: ");
	fgets(name, NAME_LEN, stdin);
	puts("");

	name[strcspn(name, "\n")] = 0;

}

//this function asks the user to enter their pet's age
int enterPetAge() {

	char* end;
	char age[AGE] = { 0 };

	printf("%s", "Please enter your pet's age: ");
	fgets(age, AGE, stdin);
	puts("");

	age[strcspn(age, "\n")] = 0;

	long validAge = strtol(age, &end, 10);

	return validAge;

}

void entryMode(char nameArray[NAME_LEN], int age, int numNames, Pet* headPtr) {

	Pet* petPtr = NULL;
	Pet* currentPtr = NULL;

	for (int i = 0; i < numNames; i++) {

		petPtr = malloc(sizeof(Pet));

		//check if memory was allocated
		if (petPtr != NULL) {

			//the case where the linked list is empty
			if (headPtr == NULL) {

				//point to proper values in the Pet structures
				strcpy(petPtr->name, nameArray);
				petPtr->age = age;

				//set head equal to first "node"
				headPtr = petPtr;

			}
			//entry by aplhabetical order
			else {

				//if the incoming name comes first in the alphabet
				if (strcmp(nameArray, headPtr->name) < 0) {

					strcpy(petPtr->name, nameArray);
					petPtr->age = age;

					petPtr->nextPetPtr = headPtr;

					headPtr = petPtr;

				}

			}

		}

	}

}