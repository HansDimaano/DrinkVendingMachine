#include <iostream>
#include <array>
#include <string>
using namespace std;

// structure for drinks
struct Drinks {  
	string name;
	float price;
	int supply;
};


// function for initialising the drinks menu
void intialiseMenu(struct Drinks *Menu) {

	Menu[0] = { "Royal", 10, 8 };
	Menu[1] = { "Pepsi", 2, 6 };
	Menu[2] = { "Water", 20, 10 };
	Menu[3] = { "Coffee", 7.5, 5 },
	Menu[4] = { "Tea   ", 8.5, 3 };
}


// function for computing the change
float computeChange(int drinkNum, float payment, struct Drinks *Menu) {

	float change;

	change = payment - Menu[drinkNum - 1].price;

	return change;
}

// main function
int main() {

	int userChoice = 0;
	float userPayment = 0, userChange = 0;
	char continueProgram;
	bool endProgram = false;

	Drinks DrinksMenu[5];

	intialiseMenu(DrinksMenu);

	cout << "WELCOME TO ENG 209 FINAL EXAMINATION'S VIRTUAL DRINK MACHINE SIMULATOR \n\n\n";

	do {

		cout << "The Product's Information is as follows:\n\n";

		cout << "Brand_Name *********************** Price *************************** Supply\n\n";

		// for loop for showing the drinks menu
		for (int i = 0; i < 5; i++) {
			cout << "(" << i + 1 << ")" // drink number
				<< DrinksMenu[i].name << "\t\t\t   " // drink name
				<< DrinksMenu[i].price << " Pesos\t\t\t\t"  // drink price
				<< DrinksMenu[i].supply << "\n"; // drink supply
		}


		// do while loop for invalid input in product choice
		do {
			cout << "\nPlease choose your product(Product Number): ";
			cin >> userChoice;

			// if invalid input
			if (userChoice < 1 || userChoice > 5) {

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nInvalid input. Please try again!\n\n";
			}

			// if supply is 0
			if (DrinksMenu[userChoice - 1].supply < 1) {

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nSadly, we don't have stack for that. Please choose another drink. \n\n";
			}

		} while (userChoice < 1 || userChoice > 5 || DrinksMenu[userChoice - 1].supply < 1);


		// do while loop for invalid input in payment
		do {
			cout << "\nPlease input money: ";
			cin >> userPayment;

			// if invalid input
			if (cin.fail()) {

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nInvalid input. Please try again!\n\n";
			}


			// if user payment is less than the price
			if (userPayment < DrinksMenu[userChoice - 1].price) {

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nPlease pay an appropriate amount of money for the drink. \n\n";
			}

		} while (cin.fail() || userPayment < DrinksMenu[userChoice - 1].price);



		userChange = computeChange(userChoice, userPayment, DrinksMenu);

		cout << "\nYou have purchased " << DrinksMenu[userChoice - 1].name;

		cout << "\n\nYour change is " << userChange << " Pesos";



		// do while loop for invalid input in continue program
		do {
			cout << "\n\nDo you want purchase again [y] to continue [n] to quit: ";
			cin >> continueProgram;

			// if invalid input
			if (cin.fail()) {

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nInvalid input. Please try again!\n\n";
			}


			// if continue program is not answered by y or n
			if (continueProgram != 'y' && continueProgram != 'n') {

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nPlease answer through [y] or [n]. \n\n";
			}

		} while (cin.fail() || (continueProgram != 'y' && continueProgram != 'n'));


		// check if users want to end the program
		if (continueProgram == 'n') {
			endProgram = true;
		}

	} while (!endProgram);
}