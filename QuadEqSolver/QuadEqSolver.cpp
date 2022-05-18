/*
 * QuadraticEquationSolver.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: Asa Hayes
 */

#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	//declarations
	float a, b, c;
	double realHalf, unrealHalf;
	double x1, x2;

	//user input of variables
	cin >> a >> b >> c;

	//finds determinant
	double determ = (b * b) - (4 * a * c);

	//prints equation from entered coefficients
	if(fmod(a,1) != 0.0){
		printf("%s%.1f%s", "", a, "x^2 ");
		if(b >= 0){
			printf("%s%.1f%s", "+ ", abs(b), "x ");
		}else{
			printf("%s%.1f%s", "- ", abs(b), "x ");
		}
		if(c >= 0){
			printf("%s%.1f%s", "+ ", abs(c), " = 0\n");
		}else{
			printf("%s%.1f%s", "- ", abs(c), " = 0\n");
		}
	}else{
		printf("%s%.0f%s", "", a, "x^2 ");
		if(b >= 0){
			printf("%s%.0f%s", "+ ", abs(b), "x ");
		}else{
			printf("%s%.0f%s", "- ", abs(b), "x ");
		}
		if(c >= 0){
			printf("%s%.0f%s", "+ ", abs(c), " = 0\n");
		}else{
			printf("%s%.0f%s", "- ", abs(c), " = 0\n");
		}
	}
	//Checks if input is valid for any solver
	if(a == 0 && b == 0){
		cout << "Unable to determine root(s)";
	}

	//Checks to see if input equation is linear, finds single root if true
	if(a == 0){
		x1 = (-c) / b;
		cout << "x =  " << x1;
	//Uses determinant to choose which solver/format to use
	//regular equation, 2 different roots
	}else if (determ > 0) {
        x1 = (-b + sqrt(determ)) / (2*a);
        x2 = (-b - sqrt(determ)) / (2*a);
        cout << "x = " << x1 << endl;
        cout << "x = " << x2;
    }
    //regular equation, 2 roots are equal
    else if (determ == 0) {
        x1 = (-b + sqrt(determ)) / (2 * a);
        cout << "x = " << x1;
    }
	//alternate equation, 2 roots have imaginary components
    else {
        realHalf = -b / (2 * a);
        unrealHalf = sqrt(-determ) / (2 * a);
        cout << "x = " << realHalf << " + " << abs(unrealHalf) << "i" << endl;
        cout << "x =  " << realHalf << " - " << abs(unrealHalf) << "i";
    }
}
