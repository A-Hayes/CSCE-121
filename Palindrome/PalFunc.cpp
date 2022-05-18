#include <iostream>
#include <string>
#include <algorithm>
#include "PalFunc.h"
using namespace std;

//prints proper usage format is input is invalid
void printUsageInfo(string exeName /* representing name of executable from command line */){
	cout << "Usage: " << exeName << " [-c] [-s] string ..." << endl;
	cout << "-c: case sensitivity turned on" << endl;
	cout << "-s: ignoring spaces turned off" << endl;
}
 
bool isPalindrome(string inputStr, bool caseSense, bool spaceSense){
	bool isPal;
 	
 	//main recursion block; breaks out of recursion at last 2 chars, true if both are ==, else false
	if((inputStr.length() < 3) && (inputStr[0] == inputStr.size() - 1)){
		isPal = true;
		return isPal;
	}else{		
     	//processes input string according to input flags
		if(caseSense == false){	//converts entire string to lowercase, preserves spaces
			transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);
		}
     
		if(spaceSense == false){ //removes all spaces in string, preserves case
			inputStr.erase(std::remove(inputStr.begin(),inputStr.end(),' '),inputStr.end());
		}
     	
     	//if any 1st/last pair of chars is not equal, break out of recursion and return false
		if(inputStr[0] != inputStr.size() - 1){
			isPal = false;
			return isPal;
		}else{	//try again, recurs with substring that removes 1st and last chars
			isPal = isPalindrome(inputStr.substr(1, inputStr.length() - 2), caseSense, spaceSense);
		}
	}
}