/*
 * mult.cpp
 *
 *  Created on: Jun 11, 2017
 *      Author: Asa Hayes
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

int main() {
    	char cont = 'y';
    	const int w = 3;

    	vector< vector<int> > tbl;

    	while (cont == 'y'){
           	int num = -1;

           	// FIXME: add comparisons for while loop that ensure exit
           	//   only if number input is between 1 and 9 inclusive
           	while ((num <= 1) || (num >= 9)){
           		cout << "Enter how many numbers for table (1-9): ";
            	cin >> num;
            	cout << endl;
           	}

           	tbl = vector< vector<int> >();

           	vector<int> row;
           	for (int i = 0; i < num; ++i) {
           		row = vector<int>();
           		for (int j = 0; j < num; ++j) {
           			row.push_back((1 + i) * (1 + j));
           		}
           		tbl.push_back(row);
           	}

           	// display normal
           	// First row
           	cout << " " << setw(w) << "|";
           	for (int i = 0; i < num; ++i) {
                   	cout << setw(w) << (i + 1);
           	}
           	cout << endl;
           	cout << "-" << setw(w) << "+";
           	// Horizontal Separator
           	for (int i = 0; i < num; ++i) {
                   	cout << setw(w) << "-";
           	}
           	cout << endl;
           	// Rows of table
           	// FIXME: add code so that this nested for loop
           	//   outputs the values in the vector
           	for (int i = 0; i < num; ++i) {
           		cout << i + 1 << "  |";
           		for (int j = 0; j < num; ++j) {
           			cout << setw(w) << (tbl[i])[j];
                }
           		cout << endl;
           	}
           	cout << endl;

           	// display reversed
           	// First row
           	cout << " " << setw(w) << "|";
           	for (int i = num - 1; i >= 0; --i) {
                   	cout << setw(w) << (i + 1);
           	}
           	cout << endl;
           	// Horizontal Separator
           	cout << "-" << setw(w) << "+";
           	for (int i = 0; i < num; ++i) {
                   	cout << setw(w) << "-";
           	}
           	cout << endl;
           	// Rows of table
           	// FIXME: add code so that this nested for loop
           	//   outputs the values in the vector
	//     HINT: should like loop above
           	for (int i = num - 1; i >= 0; --i) {
           		cout << i + 1 << "  |";
           		for (int j = num - 1; j >= 0; --j) {
           			cout << setw(w) <<(tbl[i])[j];
           		}
                cout << endl;
           	}
           	cout << endl;

           	cout << "Do you want to do another? (y/n) ";
           	cin >> cont;
           	cout << endl;
           	cont = tolower(cont);
    	}
    	return 0;
}



