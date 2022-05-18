/*
    Circle class derived from Shape class
*/

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
private:
    unsigned int radius;

public:
	Circle();
    Circle(unsigned int r, Point p, Color c);

    void set_radius(unsigned int r);
    unsigned int get_radius() const;
    
    void draw();
    void print_parameters();
};

#endif