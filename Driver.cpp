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
	pair<int, int> searchResult = { -1, -1 };

	cout << "Enter size of hash table: ";
	cin >> size; 
	HashTable table(size); 
	displayMenu();

	while (userInput != 'Q') {
		
		cout << "Make selection: ";
		cin >> userInput;
		userInput = toupper(userInput);
		cout << endl;

		switch (userInput) {
		case '+':
			cin >> value;
			table.HashTable_Insert(value);
			break;
		case '-':
			cin >> value;
			table.HashTable_Remove(value);
			break;
		case '?':
			cin >> value;
			searchResult = table.HashTable_Search(value);
			if (searchResult.second == -1)
				cout << endl << "Value doesn't exist" << endl;
			else
				cout << "Found at Bucket index: " << searchResult.first << ", node: " << searchResult.second << endl;
			break;
		case 'P':
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
	cout << STARS << endl << endl;
}