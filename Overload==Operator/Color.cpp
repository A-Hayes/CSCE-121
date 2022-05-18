
#include "Color.h"


Color::Color() : R(255), G(255), B(255){
	
}


Color::Color(int r, int g, int b): R(r), G(g), B(b){
    if (!is_valid_val(R) || !is_valid_val(G) || !is_valid_val(B)) {
        throw Color_error{};
    }
}

bool Color::operator==(const Color& rhs) const{
	if(rhs.R == R){
		if(rhs.G == G){
			if(rhs.B == B){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}

}

std::string Color::to_str() const
{
    std::stringstream ss;
    ss << '(' << R << ',' << G << ',' << B << ')';
    return ss.str();
}

bool Color::is_valid_val(int v) const
{
    if (v < 0 || v > 255)
        return false;
    else
        return true;
}

void Color::set_R(int r)
{
    if (!is_valid_val(r))
        throw Color_error{};
    R = r;
}

void Color::set_G(int g)
{
    if (!is_valid_val(g))
        throw Color_error{};
    G = g;
}

void Color::set_B(int b)
{
    if (!is_valid_val(b))
        throw Color_error{};
    B = b;
}