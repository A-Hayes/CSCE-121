/*
 * BullsAndCows.cpp
 *
 *  Created on: June 16, 2017
 *      Author: Asa Hayes
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
using namespace std;

int main() {
	vector<int> code;
	vector<int> guess;
	vector<int> tempCode;

	int codeInt, codeSize, guessInt, randUnits, cont = 1;
	int validInput = 0;
	int validCode = 0;
	string guessStr = "";
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,6);

	while(validInput == 0){
		cout << "Enter number of digits in code (3, 4 or 5): ";
		cin >> codeSize;

		if((codeSize != 0) && (codeSize != 3) && (codeSize != 4) && (codeSize != 5)){
			cout << "Invalid input ";

		}else if(codeSize == 0){

			while(validCode == 0){
				validCode = 1;
				cout << endl <<"Enter code: ";									//
				cin >> codeInt;
				cout << "Enter number of digits in code: ";
				cin >> codeSize;

				for (int i = codeSize - 1; i >= 0; --i){
					int units = pow(10, i);
				    int digit = codeInt / units % 10;
				    code.push_back(digit);
				}

				cout << endl;

				validInput = 1;											//
				tempCode = code;											//
				sort(tempCode.begin(), tempCode.end());
				for(int i = 0; i < code.size() - 1; i++) {
				    if (tempCode[i] == tempCode[i + 1]) {
				        validCode = 0;
				    }
				}
				if(validCode == 0){
					code.clear();
					tempCode.clear();
				}

			}

		}else if((codeSize == 3) || (codeSize == 4) || (codeSize == 5)){

			while(validCode == 0){
				validCode = 1;											//
				randUnits = pow(10, codeSize);
				uniform_int_distribution<int> dist(1, randUnits);
				codeInt = dist(generator);

				for (int i = codeSize - 1; i >= 0; --i){
			        int units = pow(10, i);
			        int digit = codeInt / units % 10;
			        code.push_back(digit);
				}

				tempCode = code;
				validInput = 1;											//
				sort(tempCode.begin(), tempCode.end());

				for(int i = 0; i < code.size() - 1; i++) {
				    if (tempCode[i] == tempCode[i + 1]) {
				        validCode = 0;
				    }
				}

				if(validCode == 0){
					code.clear();
				}
			}
		}

	}



	while(cont == 1){
		cout << "Number to guess: ";
		for(int k = 0; k < code.size(); k++){
			cout << code[k];
		}

		guess.clear();
		guessStr = "";
		cout << endl;
		guessInt = 0;
		int dupe = 0;
		int wrongSize = 0;
		int bull = 0;
		int cow = 0;
		int validGuess = 1;
		cout << "Enter guess: ";
		cin >> guessInt;

		int numberOfDigits = 1+floor(log10(guessInt));

		for(int k = 0; k < code.size(); k++){
			guessStr.append(to_string(code[k]));
		}

		for (int i = codeSize - 1; i >= 0; --i){
	        int units = pow(10, i);
	        int digit = guessInt / units % 10;
	        guess.push_back(digit);
		}

		for(int i = 0; i < guess.size() - 1; i++) {
			if (guess[i] == guess[i + 1]) {
				validGuess = 0;
				dupe = 1;
			}
		}

		if(numberOfDigits > codeSize){
			validGuess = 0;
			wrongSize = 1;
			dupe = 0;
		}

		if (validGuess == 0) {
			if (dupe == 1) {
				cout << "Each number must be different.";
			}
			if (wrongSize == 1) {
				cout << "You can only enter " << guess.size() << " digits.";
			}
		}

		/*
		for (int i = 0; i != guess.size(); ++i){
		    if(guess[i] == code[i]){
		        bull++;
		    }else{
		        for(int j = 1; j != guess.size(); ++j){
		            if (code[i] == guess[j]){
		                cow++;
		            }
		        }
		    }
		}
*/

	    for (int j = 0; j < guess.size(); ++j){
	        if (guess[j] == code[j]) bull++;
	    }

	    for (int i2 = 0; i2 < guess.size(); ++i2){
	        for (int j2 = 0; j2 < code.size(); ++j2){
	            if (guess[i2] == code[j2] && i2 != j2){
	            	cow++;
	        	}
	        }
	    }

		if(bull == codeSize){
			cout << bull << " bulls - " << guessStr << " is Correct!" << endl;
			cont = 0;
		}else if(validGuess == 1){
			cout << bull << " bulls" << endl;
			cout << cow << " cows" << endl;
		}else{
			cout << endl;
		}
		bull = 0;
		cow = 0;
	}



}


