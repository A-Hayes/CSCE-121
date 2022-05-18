/*
 * SwithcStructureTest.cpp
 *
 *  Created on: Jun 6, 2017
 *      Author: Asa Hayes
 */

#include <iostream>
using namespace std;
int main()
{
	char grade;
    cout << "Please enter a character grade (A, B, C, D, or F): ";
    cin >> grade;

    switch (grade)
    {
        case 'A': cout << "Great work. " << endl;
         	 	break;
        case 'a': cout << "Great work. " << endl;
                 	 	break;
        case 'B': cout << "Good work. " << endl;
        		break;
        case 'b': cout << "Good work. " << endl;
                		break;
        case 'C': cout << "Passing work. " << endl;
                break;
        case 'c': cout << "Passing work. " << endl;
                        break;
        case 'D': cout << "Poor work. " << endl;
                cout << "See your instructor." << endl;
                break;
        case 'd': cout << "Poor work. " << endl;
                cout << "See your instructor." << endl;
                break;
        case 'F': cout << "Unsatisfactory work. " << endl;
                cout << "See your instructor." << endl;
                break;
        case 'f': cout << "Unsatisfactory work. " << endl;
                cout << "See your instructor." << endl;
                break;
        default: cout << grade << " is not a legal grade. " << endl;
    }
   return 0;
}



