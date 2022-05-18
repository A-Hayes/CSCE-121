#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));

	vector<int> nums;
/*
	//EDIT1 comment out the following for loop
	// Load with random values
	for (int i=0; i<30; ++i) {
		nums.push_back(rand()%999);
	}
*/
	// EDIT2
	// Setup and use input file "nums.dat" to load values into vector

	// Input Step 1 Open file, preferably with RAII approach

	// Input Step 2 Check that file opened sucessfully

	// Input Step 3 Use file (i.e. read numbers from file into nums vector)

	// Input Step 4 Close file, preferably with RAII approach

	ifstream infs("nums.dat");
	ofstream outfs("stats.dat");
	ofstream
	if (!infs.is_open()) {
		cerr << "Failed to open in file: " << endl;
		return 1;
	}
	if (!outfs.is_open()) {
		cerr << "Failed to open out file: " << endl;
		return 1;
	}




	// Output values in vector to screen
	cout << "Unsorted values: " << endl;
	for (unsigned int i = 0; i < nums.size(); ++i) {
		cout << setw(5) << nums.at(i);
		if ((i + 1) % 5 == 0) cout << endl; // new line for each 5 numbers
	}
	cout << endl << endl;

	sort(nums.begin(), nums.end());

	// Output values in vector to screen
	cout << "Sorted values: " << endl;
	for (unsigned int i = 0; i < nums.size(); ++i) {
		cout << setw(5) << nums.at(i);
		if ((i + 1) % 5 == 0) cout << endl; // new line for each 5 numbers
	}
	cout << endl << endl;

	// next statement probably needs a comment, 
	//    but as a challenge figure out what's going on...
	double median = (nums.size() % 2) ? nums.at((nums.size() - 1) / 2) : 
		(nums.at((nums.size() - 1) / 2) + nums.at((nums.size()) / 2)) / 2.0;


	// EDIT3
	// Setup and use output file "stats.dat" to output stats data

	// Output Step 1 Open file, preferably with RAII approach

	// Output Step 2: Check that file opened successfully

	// Output Step 3: Use file (convert from using cout to output filestream)
		cout << "Min: " << nums.at(0) << endl;
		cout << "Max: " << nums.at(nums.size() - 1) << endl;
		cout << "Median: " << median << endl;

	// Output Step 4 Close, preferably with RAII approach
}
