// driver
#include "HashTable.h"
#include <iostream>
using namespace std;

void displayMenu();
const string STARS = "**********************************";

int main() {
	int size;
	int value;
	char userInput=' ';

	cout << "Enter size of hash table: ";
	cin >> size; 
	HashTable table(size); 

	while (userInput != 'Q') {
		displayMenu();
		cout << "Make selection: ";
		cin >> userInput;
		userInput = toupper(userInput);

		switch (userInput) {
		case '+':
			cout << "Enter value: ";
			cin >> value;
			table.HashTable_Insert(value);
			break;
		case '-':
			cout << "Enter value to remove: ";
			cin >> value;
			table.HashTable_Remove(value);
			break;
		case '?':
			cout << "Location if found" << endl;
			break;
		case 'P':
			cout << "Printing" << endl;
			table.HashTable_Print();
			break;
		case 'L':
			cout << "Load factor" << endl;
			break;
		case 'Q':
			cout << "Exiting" << endl;
			break;
		default:
			cout << "Invalid" << endl;
		}
	}
	
	return 0;
}
void displayMenu() {
	cout << STARS << endl;
	cout << "+: Insertion" << endl;
	cout << "-: Removal" << endl;
	cout << "?: Location" << endl;
	cout << "P: Print Hash Table" << endl;
	cout << "L: Load Factor" << endl;
	cout << "Q: Quit" << endl;
	cout << STARS << endl;
}