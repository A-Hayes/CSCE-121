/*
 * InputValidation.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: A
 */

#include <iostream>
#include <limits>
using namespace std;

int main() {

	int value = 0;

	while (value != -9) {
		cout << "Enter an integer (or -9 to exit): ";
		cin >> value;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cout << "You entered: " << value << endl << endl;
		}

		if (value == -9)
			return 0;
	}


}


