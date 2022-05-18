/*
    Base Shape class from which other shape classes can be derived, and
    Color enum and Point struct for descriptive shape object feautures.
*/

#ifndef SHAPE_H
#define SHAPE_H
#include <FL/Fl_Widget.H>

/*
    Color enum is our simple interface to FLTK's color definitions, which
    use values of type Fl_Color.
*/

enum Color {
    red = FL_RED,
    blue = FL_BLUE,
    green = FL_GREEN,
    yellow = FL_YELLOW,
    white = FL_WHITE,
    black = FL_BLACK,
    magenta = FL_MAGENTA,
    cyan = FL_CYAN,
};

/*
    Point struct, which will allow us to specify the position of our shapes
    on the display.
*/

struct Point {
    int x, y;
    Point();
    Point(int x, int y);
};

/*
    Our simple base Shape class, which allows us to define, position, and draw
    simple shapes on our display using FLTK
*/

class Shape : public Fl_Widget {
protected:
    Point position; // we define the position of a shape by its top-left corner
    Color linecolor;

public:
    Shape();
    Shape(Point p, Color c);
    
    void set_color(Color c);
    Color get_color() const;
    void set_position(Point p);
    Point get_position() const;

    virtual void draw() = 0;
    virtual void print_parameters() = 0;
};

#endif