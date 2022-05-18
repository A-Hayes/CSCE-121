#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <sstream>

class Color_error {};
class Color {
/* Public */
public:
    Color();
    Color(int r, int g, int b);
	bool operator==(const Color& rhs) const;
    std::string to_str() const;
    bool is_valid_val(int) const;
    int get_R(void) const { return R; }
    int get_G(void) const { return G; }
    int get_B(void) const { return B; }
    void set_R(int); 
    void set_G(int);
    void set_B(int);
/* Private */
private:
    int R;
    int G;
    int B;
};

//////////////////////////////////////////////////////////////////////////////
#endif