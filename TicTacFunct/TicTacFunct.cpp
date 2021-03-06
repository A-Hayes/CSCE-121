/*
 * TicTacFunct.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: Asa Hayes
 *
 *      Questions:
 *      5.
 *
 *      6.
 *
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <time.h> // for time function
#include <stdlib.h> // for srand
#include <limits> // for std::numeric_limits<int>::max()
using namespace std;

int getInteger(string label, int maxVal) {
	// Get integer with label

	// ask for value
	int val = 0;
	while (val == 0) {
		cout << "Enter " << label << ": ";
		cin >> val;
		if (cin) { // succeeded in reading integer
			if (val < 1 || val > maxVal) {
				cout << label << " " << val <<
					" not valid. Try again" << endl;
					val = 0;
			}
		} else { // probably entered a letter or special symbol
			cout << label << " " << val <<
				" not valid. Try again" << endl;
				val = 0;
				cin.clear(); // reset failbit
				//skip bad input
				cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	}
	return val;
}

void userMove(vector< vector<char> >& matrix, char user_symbol, int numRows){
	// User Move
	string label;
	bool validMove = false;

	while (!validMove) {

		int row, col;

		label = "row";
		// ********************************************************
		row = getInteger(label, numRows);
		// --------------------------------------------------------

		label = "column";
		// ********************************************************
		// Get integer with label
		col = getInteger(label, numRows);
		// ask for column
		// --------------------------------------------------------

		// row, col is valid, is it open?
		row--; col--; // adjust for 0 based indexing
		validMove = matrix.at(row).at(col) == ' ';
		if (validMove)
			matrix.at(row).at(col) = user_symbol;
		else {
			cout << "Position [" << row+1 << "," << col+1
				<< "] already occupied. Try again" << endl;
		}

	}
}

void computerMove(vector< vector<char> >& matrix, char computer_symbol, int numRows){
	// Computer Move

	cout << "Computer playing\n";
		/* Calculate a move for the computer turn to play.
		* Let's be lazy and do something very simple: move is
		* first place that is empty in the game. A losing strategy
		* :)
		*/
	bool found = false;
	for (int r = 0; !found && r < numRows; r++) {
		for (int c = 0; !found && c < numRows; c++) {
			if (matrix.at(r).at(c) == ' ') { // found empty place
				matrix.at(r).at(c) = computer_symbol;
				found = true;
			}
		}
	}
}

void printGameState(const vector< vector<char> >& matrix, int numRows){
	// print game state
	cout << "Board is:" << endl;
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numRows; c++) {
			cout << setw(2) << matrix.at(r).at(c);
			if (c < numRows -1)
				cout << setw(2) << "|";
		}
		cout << endl;
		if (r < numRows -1) {
			for (int c=0; c < numRows; c++) {
				cout << setw(2) << "-";
				if (c < numRows - 1)
					cout << setw(2) << "+";
			}
			cout << endl;
		}
	}
}

bool checkWin(const vector< vector<char> >& matrix, int numRows) {
	// check for win
	bool win = false;
	// check rows for win
	for (int r = 0; r < numRows && win == false; r++) {
		// let's see row r
		char sym = matrix.at(r).at(0);
		if (sym != ' ') { //  don't check if empty
			bool rowWin = true;
			for (int c = 1; c < numRows; c++) {
				if (matrix.at(r).at(c) != sym)
					rowWin = false;
			}
			win = win || rowWin;
		}
	}

	if (!win) {
		// check columns for win
		for (int c = 0; c < numRows && win == false; c++) {
			// let's see column c
			char sym = matrix.at(0).at(c);
			if (sym != ' ') {
				bool colWin = true;
				for (int r = 0; r < numRows; r++) {
					if (matrix.at(r).at(c) != sym)
						colWin = false;
				}
				win = win || colWin;
			}
		}
	}

	if (!win) {
		// check diagonal top left to bottom right
		char sym = matrix.at(0).at(0);
		if (sym != ' ') {
			bool diagWin = true;
			for (int r =0; r < numRows; ++r) {
				if (matrix.at(r).at(r) != sym)
					diagWin = false;
			}
			win = win || diagWin;
		}
	}

	if (!win) {
		// check diagonal bottom left to top right
		char sym = matrix.at(0).at(numRows-1);
		if (sym != ' ') {
			bool diagWin = true;
			for (int r =0; r < numRows; ++r) {
				if (matrix.at(r).at(numRows - r - 1) != sym)
					diagWin = false;
			}
			win = win || diagWin;
		}
	}
	return win;
}




int main()
{
	char play = 'y';
	while (play=='y') {
		// determine size of board
		int numRows;
		do {
			if (!cin) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "How many Rows? (3-9) ";
			cin >> numRows;
		} while (!cin.good() || (numRows<3 || numRows >9));

		char computer_symbol;
		char user_symbol = ' '; // initialize to anything except O or X

		// ask user for preferred symbol (X or O);
		while (!(user_symbol == 'X' || user_symbol == 'O')) {
			cout << "Do you want to play with X or O?" << endl;
			cin >> user_symbol;
			// ensure we only work with capital letters
			user_symbol = toupper(user_symbol);
		}
		// user_symbol will be X or O


		// initialize computer_symbol based on user choice
		if (user_symbol == 'X') {
			computer_symbol = 'O';
		} else if (user_symbol == 'O') {
			computer_symbol = 'X';
		}

		/* determine who plays first (user or program) by generating
		 * random choice
		 */
		srand (time(NULL)); // initializing random seed
		bool user_turn = true;

		if (rand() % 2 == 0) { // it is either 0 or 1
			user_turn = false;
			cout << "Computer will play first" << endl;
		} else {
			cout << "User will play first" << endl;
		}

		// declare and define matrix to represent game state
		//   (using C++11 initialization feature)
		vector< vector<char> > matrix =
		vector< vector<char> >(numRows, vector<char>(numRows,' '));

		bool game_over = false;
		bool win = false;
		int turn = 0;

		while (!game_over) {
			// determine move
			if (user_turn) {
				// ************************************************************
				userMove(matrix, user_symbol, numRows);
				// ------------------------------------------------------------

			} else {
				// ************************************************************
				computerMove(matrix, computer_symbol, numRows);
				// ------------------------------------------------------------
			}

			// ****************************************************************
			printGameState(matrix, numRows);
			// ----------------------------------------------------------------

			// ****************************************************************
			win = checkWin(matrix, numRows);
			// ----------------------------------------------------------------

			turn ++;

			// it is a tie if not a win and 9 turns
			if (win || turn >= numRows*numRows) {
				game_over = true;
			} else {
				user_turn = !user_turn;
			}
		}

		// output result
		if (win) {
			if (user_turn) { // user was last to play
					cout << "Congratulations you won!";
			} else {
					cout << "The computer won!";
			}
		} else {
			cout << "The game resulted in a tie";
		}
		cout << endl;

		cout << "Play again? (y/n) ";
		cin >> play;
	}
}


