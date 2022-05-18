/*
Program calculates the volume of various shapes based on user input.

Step 1: Compile and Run this program as-is
*/
#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <string>
#include "volume.h"
#include "otherFunct.h"
using namespace std;

const double pi = 3.14;

int main() {
	int minVal = 1;
	int maxVal = 4;
	cout << "Volume Calculator:" << endl;
	int choice = 0;
	while (choice != maxVal) {
		try {
			printMenu();
			choice = getRange(minVal, maxVal, "Enter choice: ");
			processChoice(choice);
		}
		catch (runtime_error& e) {
			cout << endl << e.what() << endl;
		}
	}
}
