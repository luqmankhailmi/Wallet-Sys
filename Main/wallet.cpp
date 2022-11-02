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
	cout << " 3 - REMOVE ACCOUNT" << endl;
	cout << " 4 - ADD EXPENSES" << endl;
	cout << " 5 - EXPENSES HISTORY" << endl;
	cout << "-----------------------------------" << endl;
}

//----------------------------------------------------------------------------------------------

void accountsList(string acc[100][100]) {
	cout << "-----------------------------------" << endl;
	cout << " ACCOUNTS LIST" << endl;
	bool endOfList = false;
	int iterator = 0;
	while (endOfList == false) {
		if (acc[iterator][0].length() != 0) {
			cout << " " << iterator + 1 << ". " << acc[iterator][0] << " = RM " << acc[iterator][1] << endl;
			iterator++;
		}
		else {
			endOfList = true;
		}
	}
	cout << "-----------------------------------" << endl;
}

int main() {
	// accounts-----------------------
	string accounts[100][100];
	string expensesHistory[100][100];
	
	// expenses------------------------
	string title[100][100];
	string value[100][100];
	
	// test variable--------------------
	// accounts[0][0] = "Bank Islam";
	// accounts[0][1] = "10000";
	
	// accounts[1][0] = "Savings";
	// accounts[1][1] = "99";
	//----------------------------------
	string key;
	
	bool mainBool = true;
	while (mainBool == true) {
		mainMenu();
		cout << " Enter key: ";
		cin >> key;
		
		//-------------------------------------------------------------------------------
		// ACCOUNTS LIST
		
		if (key == "1") {
			accountsList(accounts);
			bool quit = false;
			cout << " Press \'q\' to quit : ";
			string qkey;
			cin >> qkey;
			while (quit == false) {
				if (qkey == "q") {
					quit = true;
				} else {
					cout << " Invalid key!";
				}
			}
		} //-----------------------------------------------------------------------------
		// ADD ACCOUNT
		
		else if (key == "2") {
			cout << "-----------------------------------" << endl;
			cout << " ADD ACCOUNT" << endl;
			
			// input data into accounts list
			int iterator = 0;
			bool continueSearch = true;
			while (continueSearch == true) {
				if (accounts[iterator][0].length() == 0) {
					cout << " Input account name : ";
					cin >> accounts[iterator][0];
					cout << " Input value : RM ";
					string accountValue;
					cin >> accounts[iterator][1];
					continueSearch = false;
				} else {
					iterator++;
				}
			}
		}
		//------------------------------------------------------------------------------
		// REMOVE ACCOUNTS
		
		else if (key == "3") {
			cout << "---------------------------" << endl;
			cout << " REMOVE ACCOUNTS" << endl;
			bool endOfListRemove = false;
			int iteratorRemove = 0;
			while (endOfListRemove == false) {
				if (accounts[iteratorRemove][0].length() != 0) {
					cout << " " << iteratorRemove + 1 << ". " << accounts[iteratorRemove][0] << " = RM " << accounts[iteratorRemove][1] << endl;
					iteratorRemove++;
				}
				else {
					endOfListRemove = true;
				}
			}
			
			bool quitRemove = false;
			while (quitRemove == false) {
				cout << " Choose an account to be remove(key) or \'0\' to quit'': ";
				int keyRemove;
				cin >> keyRemove;
				
				// continue here
				if (keyRemove != 0) {
					if (accounts[keyRemove - 1][0].length() != 0) {
						accounts[keyRemove - 1][0] = "";
						accounts[keyRemove - 1][1] = "";
						
						cout << " Account has been successfully removed" << endl;
						cout << " Press \'q\' to exit : ";
						
						bool reallyQuit = false;
						while (reallyQuit == false) {
							string quitRemove;
							cin >> quitRemove;
							if (quitRemove == "q") {
								reallyQuit = true;
							}
						}
				    }
				} else if (keyRemove == 0) {
					quitRemove = true;
				}
				quitRemove = true;
				
			}
		}
		//---------------------------------------------------------------------------------
		// ADD EXPENSE
		else if (key == "4") {
			cout << "------------------------------------" << endl;
			cout << " ADD EXPENSES" << endl;
			accountsList(accounts);
			cout << " Choose account : ";
			int keyAccount;
			cin >> keyAccount;
			
			bool checked = false;
			while (checked = false) {
				if (accounts[keyAccount - 1][0].length() != 0) {
					cout << " Account selected : " << accounts[keyAccount][0] << endl;
					cout << "Title : ";
					cin >> title[keyAccount - 1][0];
					cout << "Value : ";
					cin >> value[keyAccount - 1][1];
					checked = true;
					cout << "Title added to list!"; 
				}
			}
		}
		
	}
	return 0;
}
