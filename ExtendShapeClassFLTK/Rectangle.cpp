/*
    Rectangle class derived from Shape class
*/

#include <iostream>
#include <FL/fl_draw.H>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle()
    : Shape(Point(0,0), black), width(0), height(0) {}

Rectangle::Rectangle(unsigned int w, unsigned int h, Point p, Color c)
    : Shape(p, c), width(w), height(h) {}

void Rectangle::set_width(unsigned int w) {
    this->width = w;
}

unsigned int Rectangle::get_width() const {
    return this->width;
}

void Rectangle::set_height(unsigned int h) {
    this->height = h;
}

unsigned int Rectangle::get_height() const {
    return this->height;
}

void Rectangle::draw() {
	// setcolor
	fl_color(linecolor);
	// draw shape
	fl_rect(position.x, position.y, width, height);
}

void Rectangle::print_parameters() {
	cout << "Rectangle:" << endl << 
	"Width: " << width << " Height: " << height <<
	" Point(" << position.x << ", " << position.y << ")" << endl;
}
