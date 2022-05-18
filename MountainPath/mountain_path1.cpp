#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include "functions.h"

//#define DEBUG

using namespace std;

/**
	Application entry point
*/
int main( void ) {
	// Get user input -- number of columns (image width)
	cout << "Please input the number of columns: ";
	int columns = 0;
	while( !( cin >> columns ) ) {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Error: Invalid input." << endl;
		cout << "Please input the number of columns: ";
	}

	// Get user input -- number of rows (image height)
	cout << "Please input the number of rows: ";
	int rows = 0;
	while ( !( cin >> rows ) ) {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Error: Invalid input." << endl;
		cout << "Please input the number of rows: ";
	}

	// Get user input -- name of file
	cout << "Please input the file name: ";
	string input_file_name = "";
	while( !( cin >> input_file_name ) ) {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Error: Invalid input." << endl;
		cout << "Please input the file name: ";
	}

	// Read data from file
	vector<vector<int>> height_map;

	ifstream input_file;
	input_file.open( input_file_name.c_str() );
	for ( int r = 0; r < rows; ++r ) {
		vector<int> temp_row;
		for ( int c = 0; c < columns; ++c ) {
			int data;
			
			// Read in each data point from the file
			if (input_file >> data){
				temp_row.push_back( data );
			} else {
				cout << "Error: not enough data!" << endl;
				return 1;
			}
		}
		height_map.push_back( temp_row );
	}
	input_file.close();

	// Find minimum and maximum elevation
	int min_elevation = find_minimum( height_map );
	int max_elevation = find_maximum( height_map );

	// Compute the shade of gray for each cell in the map
	vector<vector<int>> v_brightness;
	for ( int r = 0; r < height_map.size(); ++r ) {
		vector<int> temp_col;
		for ( int c = 0; c < height_map[r].size(); ++c ) {
			int gray_value = calculate_gray( height_map[r][c], min_elevation, max_elevation );
			temp_col.push_back( gray_value );
		}
		v_brightness.push_back(temp_col);
	}
	
	vector< vector<int> > v_red;
	vector< vector<int> > v_green;
	vector< vector<int> > v_blue;
	
	for (int r = 0; r < v_brightness.size(); ++r) {
		vector<int> temp_row;
		
		for (int c = 0; c < v_brightness[r].size(); ++c) {
			temp_row.push_back( v_brightness[r][c] );
		}
		v_red.push_back( temp_row );
		v_green.push_back( temp_row );
		v_blue.push_back( temp_row );
	}
	
#ifdef DEBUG
	for (int r = 0; r < v_brightness.size(); ++r) {
		vector<int> temp_row;
		for (int c = 0; c < v_brightness[0].size(); ++c) {
			cout << v_brightness[r][c] << endl;
		}
	}	
#endif	
	
	
//*
	// Map one greedy path per row
	int min_dist = numeric_limits<int>::max();
	int min_path = 0;
	for(int i = 0; i < rows; ++i){
		int temp_dist = colorPath(height_map, v_red, v_green, v_blue, 252, 25, 63, i);
		
		if(temp_dist < min_dist){
			min_dist = temp_dist;
			min_path = i;
		}
	}

	// Map shortest greedy path
	colorPath(height_map, v_red, v_green, v_blue, 31, 253, 13, min_path);

	// Produce the output file (PPM)
	string output_file_name = input_file_name + string(".ppm");
	ofstream output_file;
	output_file.open( output_file_name.c_str() );
	output_file << "P3" << endl;
	output_file << columns << " " << rows << endl;
	output_file << "255" << endl;
	for ( int r = 0; r < v_brightness.size(); ++r ) {
		for ( int c = 0; c < v_brightness[r].size(); ++c ) {
			output_file << v_red[r][c] << " " << v_green[r][c] << " " << v_blue[r][c] << " ";
		}
	}
	output_file.close();

	// Completed successfully
	return 0;
}
