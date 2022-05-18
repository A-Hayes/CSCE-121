/**
	author: Josiah Egner
*/

#include "functions.h"

#include <cmath>	// for absolute value
#include <limits>	// for representations of infinity

using namespace std;

int find_minimum( const vector<vector<int>>& v ) {
	int min = numeric_limits<int>::max();
	
	for ( int r = 0; r < v.size(); ++r ) {
		for ( int c = 0; c < v[r].size(); c++ ) {
			if ( v[r][c] < min ) {
				min = v[r][c];
			}
		}
	}

	return min;
}

int find_maximum( const vector<vector<int>>& v ) {
	int max = -numeric_limits<int>::max();
	
	for ( int r = 0; r < v.size(); r++ ) {
		for ( int c = 0; c < v[r].size(); c++ ) {
			if ( v[r][c] > max ) {
				max = v[r][c];
			}
		}
	}

	return max;
}

int calculate_gray( int elevation, int min_elevation, int max_elevation ) {
	return (int)( ( (float)( elevation - min_elevation ) / ( max_elevation - min_elevation ) ) * 255.0f );
}

int color_path( const vector<vector<int>>& height_map, vector<vector<int>>& v_red, vector<vector<int>>& v_green, vector<vector<int>>& v_blue, int color_r, int color_g, int color_b, int start_row ) {
	// Initialize variables
	int total_distance = 0;
	
	// Traverse the map by iterating through columns
	int row = start_row;
	for ( int column = 0; column < height_map[row].size(); ++column ) {
		// Color the cell we are at with the provided RGB values
		v_red[row][column] = color_r;
		v_green[row][column] = color_g;
		v_blue[row][column] = color_b;

		// If we are on the last column, we're done
		if ( column >= height_map[row].size() - 1 ) {
			break;
		}

		// Generate movement possibilities by calculating their vertical distance
		// from the current position in the height map
		int minimum_distance = numeric_limits<int>::max();
		
		int distance_up;
		if ( row <= 0 ) {
			// If we are on the first row, set up distance to infinity
			// to eliminate it from the decision-making process
			distance_up = numeric_limits<int>::max();
		} else {
			distance_up = abs( height_map[row - 1][column + 1] - height_map[row][column] );
		}
		
		int distance_middle = abs( height_map[row][column + 1] - height_map[row][column] );

		int distance_down;
		if ( row >= height_map.size() - 1 ) {
			// If we are on the last row, set down distance to infinity
			// to eliminate it from the decision-making process
			distance_down = numeric_limits<int>::max();
		} else {
			distance_down = abs( height_map[row + 1][column + 1] - height_map[row][column] );
		}
		
		// Decide which route to take based on shortest vertical distance
		if ( distance_up < distance_middle ) {
			if( distance_up < distance_down ) {
				// Move up
				minimum_distance = distance_up;
				--row;
			} else if( distance_up == distance_down ) {
				// Favor moving down
				minimum_distance = distance_down;
				++row;
			} else {
				// Move down
				minimum_distance = distance_down;
				++row;
			}
		} else if( distance_up == distance_middle ) {
			if ( distance_up < distance_down ) {
				// Favor moving middle
				minimum_distance = distance_middle;
			} else if( distance_up == distance_down ) {
				// Favor moving middle
				minimum_distance = distance_middle;
			} else {
				// Move down
				minimum_distance = distance_down;
				++row;
			}
		}else{
			if( distance_middle < distance_down ){
				// Move mid
				minimum_distance = distance_middle;
			}else if( distance_middle == distance_down ){
				// Favor moving mid
				minimum_distance = distance_middle;
			}else{
				// Move down
				minimum_distance = distance_down;
				++row;
			}
		}

		// Update the total distance we have travelled
		total_distance += minimum_distance;
	}

	return total_distance;
}
