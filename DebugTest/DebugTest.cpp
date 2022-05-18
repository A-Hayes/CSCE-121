#include <iostream>

using namespace std;

int main() {
	char choice = 'A';
	double celsiusTemp = 0.0;
	double fahrenheitTemp = 0.0;
	// print menu
	cout << "1: Convert Celsius to Fahrenheit" << endl;
	cout << "2: Convert Fahrenheit to Celsius" << endl;

	//  Get option
	cout << "Input conversion option (1 or 2): ";
	cin >> choice;
	cout << endl;

	// Get base temperature
	cout << "Enter temperature in ";
	if (choice == '1')
		cout << "Celsius";
	else
		cout << "Fahrenheit";
	cout << ": ";

	if (choice == '1') {
		// process conversion from celcius to fahrenheit
		cin >> celsiusTemp;
		fahrenheitTemp = (1.8 * celsiusTemp) + 32;
		cout << celsiusTemp << "C = " << fahrenheitTemp << "F" << endl;
	}
	else {
		// process conversion from fahrenheit to celcius
		cin >> fahrenheitTemp;
		celsiusTemp = (5.0/9.0) * (fahrenheitTemp - 32);
		cout << fahrenheitTemp << "F = " << celsiusTemp << "C" << endl;
	}

	// uncomment line below if using Visual Studio
	//system("pause");
}
