#ifndef PAL_H
#define PAL_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printUsageInfo(string exeName /* representing name of executable from command line */);
bool isPalindrome(string inputString, bool caseSense, bool spaceSense);

#endif