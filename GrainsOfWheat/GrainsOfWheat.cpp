/*
 * GrainsOfWheat.cpp
 *
 *  Created on: Jun 11, 2017
 *      Author: Asa Hayes
 */

// must compile on build.tamu.edu
#include <string>
#include <limits>
#include "/home/faculty/jmichael/csce121/grainsOfWheat/Precision.h"
using namespace std;

int main () {
    // change the **type** of grains_of_wheat variable when needed
    int grains_of_wheat = 1;
    // 8X8 (change **total_squares** value to experiment with how many squares)
    int total_squares = 64;

    for ( int square_no = 1 ; square_no <= total_squares ; ++square_no )
    {
        cout << "[" << square_no << "] " << full_precision(grains_of_wheat) << endl;
        grains_of_wheat += grains_of_wheat;
    }
    return 0;
}


