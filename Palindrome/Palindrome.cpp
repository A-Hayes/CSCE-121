#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "PalFunc.h"
using namespace std;

int main(int argc, char* argv[]){	//Default main parameter for command line input
	// argc is number of arguments, argv is array that stores arguments
	int startIndex = 1;
	bool caseSense;
	bool spaceSense;
	bool isDash = true;
 	bool isPal;
 	vector<string> args(argv, argv+argc);
 
 	//2 condition blocks to handle invalid input
	if(argc < 2){
		printUsageInfo(args[0]);
		exit(1);
	}
	
	if((argc < 3) && (args[1][0] == '-')){
		printUsageInfo(args[0]);
		exit(1);
	}
 
	// argv[0] is the name of the exe, argv[1] is the first userset arg
 
 	//determines which parameters have been input and sets booleans accordingly
	int i = 1;
	while(isDash = true){
		if(args[i][0] != '-'){
         	isDash = false;
			startIndex = i;
			break;
		}else{
			string param = args[i];
			
         	int findc = param.find('c');
            int findC = param.find('C');
            int finds = param.find('s');
            int findS = param.find('S');
            	
			if((findc != string::npos) || (findC != string::npos)){
				caseSense = true;
			}
         
			if((finds != string::npos) || (findS != string::npos)){
				spaceSense = true;
			}
			i++;
		}
	}
	
 	//loop thru all arguments past filename and -s/-c args and determines if each is a palindrome using recursion
	for(i = startIndex; i < argc; i++){
		isPal = isPalindrome(args[i], caseSense, spaceSense);
		
		if(isPal){
			cout << "\"" << args[i] << "\" is a palindrome" << endl;
		}else{
			cout << "\"" << args[i] << "\" is not a palindrome" << endl;
		}
	}
	
}		