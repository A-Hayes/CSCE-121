#include <vector>

using namespace std;

/**
	Finds the minimum value in a matrix
*/
int find_minimum( const vector<vector<int>>& v);

/**
	Finds the maximum value in a matrix
*/
int find_maximum( const vector<vector<int>>& v);

/**
	Computes the value of gray for a cell on the height map
*/
int calculate_gray( int elevation, int min_elevation, int max_elevation );

/**
	Computes the greedy path starting at the given row, colors it with the provided RGB color value, returns total vertical movement.
	
	heightMap		- elevation data
	
	r			= red values for an RGB color value for the corresponding (column, row) in the elevation data
	g			= green values for an RGB color value for the corresponding (column, row) in the elevation data
	b			= blue values for an RGB color value for the corresponding (column, row) in the elevation data
	
	color_r		= The actual value to be stored in the red value vector for the given position.
	color_g		= The actual value to be stored in the green value vector for the given position.
	color_b		= The actual value to be stored in the blue value vector for the given position.
	
	start_row 	= The index of the starting row that the path will be drawn on.
*/
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int start_row);