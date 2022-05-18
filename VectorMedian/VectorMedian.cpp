/*
 * VectorMedian.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: A
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    // get a seed value for the pseudo-random number generator (no cout prompt)
    cout << "Enter seed value: ";
    int rseed;
    cin >> rseed;
    srand(rseed);
    cout << endl;

    // define constants for random values
    const int NUM_VALUES = 100;
    const int RANGE = 10000;

    // populate a vector with random values
    vector<int> values;
    for (int i = 0; i < NUM_VALUES; i++)
    {
        int val = rand() % RANGE;
        values.push_back(val);
    }

    sort (values.begin(), values.end());

    // iterate through vector and print values
    // COMMENT OUT OR REMOVE THIS FOR LOOP FOR YOUR VOCAREUM SUBMISSION
    for (int i = 0; i < NUM_VALUES; i++)
    {
        cout << setw(5) << values.at(i);
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;

    int min, max, median;

    min = values.at(0);
    max = values.at(99);
    median = (values.at(49) + values.at(50)) / 2;

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Median: " << median << endl;
}


