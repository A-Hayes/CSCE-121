/*
 * GetlineVsExtr.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: A
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{

    string searchTerms;
    double maxPrice = 50;


    cout << "Enter Maximum Price: ";
    cin >> maxPrice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    cout << "Enter Search Terms: ";

    cin >> searchTerms;

    getline(cin, searchTerms);

    cout << endl << "Searching for: " << searchTerms << endl;
    cout << "With a maximum price of: " << maxPrice << endl;

}


