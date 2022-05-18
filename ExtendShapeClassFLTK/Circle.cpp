/*
    Circle class derived from Shape class
*/

#include <iostream>
#include <FL/fl_draw.H>
#include "Circle.h"

using namespace std;

Circle::Circle()
    : Shape(Point(0,0), black), radius(0) {}

Circle::Circle(unsigned int r, Point p, Color c)
    : Shape(p, c), radius(r) {}

void Circle::set_radius(unsigned int r) {
    this->radius = r;
}

unsigned int Circle::get_radius() const {
    return this->radius;
}

void Circle::draw() {
	// setcolor
	fl_color(linecolor);
	// draw shape
	fl_arc(position.x, position.y, 2*radius, 2*radius, 0, 360);
}

void Circle::print_parameters() {
	cout << "Circle:" << endl << 
	"Radius: " << radius << 
	" Point(" << position.x << ", " << position.y << ")" << endl;
}
