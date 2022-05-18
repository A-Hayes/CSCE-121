#include "Node.h"

std::ostream& operator<<(std::ostream& os, const Node& n) {
    os << n.value;
    return os;
}
