#include <iostream>
#include <string.h>
using namespace std;


void mainMenu() {
	// main menu
	cout << "-----------------------------------" << endl;
	cout << " WALLET MENU" << endl;
	cout << "-----------------------------------" << endl;
	cout << " 1 - ACCOUNTS" << endl;
	cout << " 2 - ADD ACCOUNT" << endl;
	cout << " 3 - ADD EXPENSES" << endl;
	cout << " 4 - EXPENSES HISTORY" << endl;
	cout << "-----------------------------------" << endl;
}

//----------------------------------------------------------------------------------------------

void accountsList(string acc[100][100]) {
	bool endOfList = false;
	int iterator = 0;
	while (endOfList == false) {
		if (acc[iterator][0].length() != 0) {
			cout << iterator + 1 << ". " << acc[iterator][0] << " = RM " << acc[iterator][1] << endl;
			iterator++;
		}
		else {
			endOfList = true;
		}
	}
}

int main() {
	string accounts[100][100];
	string expensesHistory[100][100];
	
	// test variable--------------------
	accounts[0][0] = "Bank Islam";
	accounts[0][1] = "10000";
	
	accounts[1][0] = "Savings";
	accounts[1][1] = "99";
	//----------------------------------
	string key;
	
	bool mainBool = true;
	while (mainBool == true) {
		mainMenu();
		cout << "Enter key: ";
		cin >> key;
		
		if (key == "1") {
			accountsList(accounts);
			bool quit = false;
			cout << "Press \'q\' to quit.";
			string qkey;
			cin >> qkey;
			while (quit == false) {
				if (qkey == "q") {
					quit = true;
				} else {
					cout << "Invalid key!";
				}
			}
		}
	}
	return 0;
}
