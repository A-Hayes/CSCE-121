/*
    Rectangle class derived from Shape class
*/

#ifndef RECTANGLE_H
#define	RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
private:
    unsigned int width, height;

public:
	Rectangle();
    Rectangle(unsigned int w, unsigned int h, Point p, Color c);

    void set_width(unsigned int w);
    unsigned int get_width() const;
    void set_height(unsigned int h);
    unsigned int get_height() const;
    
    void draw();
    void print_parameters();
};

#endif