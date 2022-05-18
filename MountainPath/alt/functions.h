/**
	author: Josiah Egner
*/

#include <vector>

using namespace std;

/**
	Finds the minimum value in a 2D vector
*/
int find_minimum( const vector<vector<int>>& v );

/**
	Finds the maximum value in a 2D vector
*/
int find_maximum( const vector<vector<int>>& v );

/**
	Computes the value of gray for a cell on the height map scaled to [0, 255]
*/
int calculate_gray( int elevation, int min_elevation, int max_elevation );

/**
	Computes the greedy path across a height map starting on a given row. More specifically, it moves across
	columns by choosing to move up-right, right, or down-right. Favors right then down-right.

	height_map	- elevation data

	v_red		- red values for an RGB color value for the corresponding (column, row) in the elevation data
	v_green		- green values for an RGB color value for the corresponding (column, row) in the elevation data
	v_blue		- blue values for an RGB color value for the corresponding (column, row) in the elevation data

	color_r		- the actual value for the red channel in the RGB color
	color_g		- the actual value for the green channel in the RGB color
	color_b		- the actual value for the blue channel in the RGB color

	start_row 	- the index of the starting row for the path
	
	Returns the total vertical distance travelled by the greedy path.
*/
int color_path( const vector<vector<int>>& height_map, vector<vector<int>>& v_red, vector<vector<int>>& v_green, vector<vector<int>>& v_blue, int color_r, int color_g, int color_b, int start_row );
