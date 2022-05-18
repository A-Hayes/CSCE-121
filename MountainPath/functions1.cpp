#include "functions.h"
#include <limits>
#include <cmath>
#include <string>
#include <iostream>

//#define DEBUG

int find_minimum( const vector<vector<int>>& v) {								
	int min = numeric_limits<int>::max();
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[0].size(); j++){
			if(v[i][j] < min){
				min = v[i][j]; 
			}
		}
	}
	return min;
}

int find_maximum( const vector<vector<int>>& v) {								
	int max = -numeric_limits<int>::max();
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[0].size(); j++){
			if(v[i][j] > max){
				max = v[i][j]; 
			}
		}
	}
	return max;
}

int calculate_gray( int elevation, int min_elevation, int max_elevation ) {		
	// scales the position of elevation between min_elevation and max_elevation to be [0, 255]
	return (int)( ( (float)( elevation - min_elevation ) / ( max_elevation - min_elevation ) ) * 255.0f );
}

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int start_row) {										
	int total_dist = 0;

	// loop until we reach the last column
	for(int col = 0; col < heightMap[row].size() ; ++col){
		// color the cell we are at with the provided RGB values
		r[row][col] = color_r;												
		g[row][col] = color_g;											
		b[row][col] = color_b;
		
		// if we are on the last column
		if(col >= heightMap[row].size()  - 1){
			break;
		}
		
		// compute your next position
		int min_dist = numeric_limits<int>::max(); 
		int mid = abs(heightMap[row][col + 1] - heightMap[row][col]);

		// allows moving down only if row is not bottom
		int down = 0;
		if(row >= heightMap.size() - 1){
			down = numeric_limits<int>::max();
		}else{
			down = abs(heightMap[row + 1][col + 1] - heightMap[row][col]);
		}	
		
		// allows moving down only if row is not top
		int up = 0;
		if(row <= 0){
			up = numeric_limits<int>::max();
		}else{
			up = abs(heightMap[row - 1][col + 1] - heightMap[row][col]);
		}
		
		//condition block to determine which path to choose based on lowest value
		if( up < mid ){
			if( up < down ){
				// move up
				min_dist = up;
				--row;
				//cout << "up" << endl;
			}else if( up == down ){
				// favor moving down
				min_dist = down;
				++row;
				//cout << "down" << endl;
			}else{
				// move down
				min_dist = down;
				++row;
				//cout << "down" << endl;
			}
		}else if( up == mid ){
			if( up < down ){
				// favor moving mid
				min_dist = mid;
				//cout << "mid" << endl;
			}else if( up == down ){
				// favor moving mid
				min_dist = mid;
				//cout << "mid" << endl;
			}else{
				// move down
				min_dist = down;
				++row;
				//cout << "down" << endl;
			}
		}else{
			if( mid < down ){
				// move mid
				min_dist = mid;
				//cout << "mid" << endl;
			}else if( mid == down ){
				// favor moving mid
				min_dist = mid;
				//cout << "mid" << endl;
			}else{
				// move down
				min_dist = down;
				++row;
				//cout << "down" << endl;
			}
		}
		// adds the distance found in the condition block to the total distance
		total_dist += min_dist;
	}
	return total_dist;
}