/*
 * volume.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: A
 */

#include <limits>
#include <string>
using namespace std;


// Volume of a sphere: 4/3 pi r^3
double volume(double r) { // r is radius
	const double pi = 3.14;
	return pi * r*r*r * 4 / 3;
}

// Volume of a cube: a^3
double volume(int a) { // a is length of side
	return a*a*a;
}

// Volume of a cylinder: (pi r^2) * h [area of circle times height]
double volume(double r, int h) { // r is radius, h is height
	const double pi = 3.14;
	return pi * r*r * h;
}


