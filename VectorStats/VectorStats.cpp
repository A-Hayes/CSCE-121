/*
 * VectorStats.cpp
 *
 *  Created on: Jun 11, 2017
 *      Author: Asa Hayes
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
    // get a seed value for the pseudo-random number generator
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

    int min = 10000, max = 0;
    double avg, sum;

    for (int i = 0; i < NUM_VALUES; i++){
    	if(values.at(i) > max){
    		max = values.at(i);
    	}
    	if(values.at(i) < min){
    		min = values.at(i);
    	}
    	sum = sum + values.at(i);
    }
    avg = sum / NUM_VALUES;

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << avg << endl;
}


