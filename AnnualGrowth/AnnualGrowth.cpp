/*
 * AnnualGrowth.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Asa Hayes
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  string firstName = "";
  string lastName = "";
  int birthYear = 0;
  int currentAge = 0;
  double heightFeet = 0;
  double heightInch = 0;
  double heightCM = 0;
  double growthRate = 0;

 //cout << "What is your first name?: ";
   cin >> firstName;

 //cout << "What is your last name?: ";
   cin >> lastName;

 //out << "What year were you born in?: ";
   cin >> birthYear;

 //cout << "How many feet tall are you, without inches?: ";
   cin >> heightFeet;

 //cout << "How many inches tall are you, past the nearest foot?: ";
   cin >> heightInch;

   heightCM = ((heightFeet * 12) + heightInch) * 2.54;
   currentAge = 2017 - birthYear;

   growthRate = (heightCM - 51.0) / currentAge;

   cout << "Hello " << firstName << " " << lastName;
   cout << ". You are " << currentAge << " years old in 2017, and your height is " << heightCM << " cm. ";
   cout << "That means that you grew an average of " << growthRate << " cm per year (assuming you were 51 cm at birth).";
}
