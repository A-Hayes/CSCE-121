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
	
#ifdef DEBUG
	cout << "Columns: " << columns << endl;
#endif

	// Get user input -- number of rows (image height)
	cout << "Please input the number of rows: ";
	int rows = 0;
	while ( !( cin >> rows ) ) {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Error: Invalid input." << endl;
		cout << "Please input the number of rows: ";
	}

#ifdef DEBUG
	cout << "Rows: " << rows << endl;
#endif

	// Get user input -- name of file
	cout << "Please input the file name: ";
	string input_file_name = "";
	while( !( cin >> input_file_name ) ) {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Error: Invalid input." << endl;
		cout << "Please input the file name: ";
	}

#ifdef DEBUG
	cout << "File Name: " << input_file_name << endl;
#endif

	// Read data from file
	vector<vector<int>> height_map;

	ifstream input_file;
	input_file.open( input_file_name.c_str() );
	for ( int c = 0; c < columns; ++c ) {
		vector<int> temp_row;
		for ( int r = 0; r < rows; ++r ) {
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

#ifdef DEBUG
	cout << "Height Map: " << endl;
	for ( int c = 0; c < height_map.size(); ++c ) {
		for ( int r = 0; r < height_map[0].size(); ++r ) {
			cout << height_map[c][r] << " ";
		}
		cout << endl;
	}
#endif

	// Find minimum and maximum elevation
	int min_elevation = find_minimum( height_map );
	int max_elevation = find_maximum( height_map );

#ifdef DEBUG
	cout << "Min Elevation: " << min_elevation << endl;
	cout << "Max Elevation: " << max_elevation << endl;
#endif

	// Compute the shade of gray for each cell in the map
	vector<vector<int>> v_brightness;
	for ( int c = 0; c < height_map.size(); ++c ) {
		vector<int> temp_row;
		for ( int r = 0; r < height_map[0].size(); ++r ) {
			int gray_value = calculate_gray( height_map[c][r], min_elevation, max_elevation );
			temp_row.push_back( gray_value );
		}
		v_brightness.push_back(temp_row);
	}
	
	vector< vector<int> > v_red;
	vector< vector<int> > v_green;
	vector< vector<int> > v_blue;
	
	for (int c = 0; c < v_brightness.size(); ++c) {
		vector<int> temp_row;
		for (int r = 0; r < v_brightness[c].size(); ++r) {
			temp_row.push_back( v_brightness[c][r] );
		}
		v_red.push_back( temp_row );
		v_green.push_back( temp_row );
		v_blue.push_back( temp_row );
	}

	// Map one greedy path per row
	int min_dist = numeric_limits<int>::max();
	int min_path = 0;
	
	for(int i = 0; i < rows; ++i){
		cout << i << endl;
		int temp_dist = colorPath(height_map, v_red, v_green, v_blue, 252, 25, 63, i);
		
		if(temp_dist < min_dist){
			min_dist = temp_dist;
			min_path = i;
		}
	}
	
/* 	// Map shortest greedy path
	colorPath(height_map, v_red, v_green, v_blue, 31, 253, 13, min_path);
 */
	// Produce the output file (PPM)
	string output_file_name = input_file_name + string(".ppm");
	ofstream output_file;
	output_file.open( output_file_name.c_str() );
	output_file << "P3" << endl;
	output_file << columns << " " << rows << endl;
	output_file << "255" << endl;
	for ( int c = 0; c < v_brightness.size(); ++c ) {
		for ( int r = 0; r < v_brightness[c].size(); ++r ) {
			output_file << v_red[c][r] << " " << v_green[c][r] << " " << v_blue[c][r] << " ";
		}
	}
	output_file.close();

	// Completed successfully
	return 0;
}
