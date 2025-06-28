#include <iostream>

class Vector2D {
   public:
    float x, y;

    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

    // Overload the + operator
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
};

// Overload the << operator for std::ostream
std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    os << "Vector2D(" << vec.x << ", " << vec.y << ")";
    return os;
}

int main() {
    Vector2D v1(2, 3);
    Vector2D v2(4, 5);
    std::cout << std::endl;

    // Use the overloaded + operator
    Vector2D v3 = v1 + v2;

    // Use the overloaded << operator
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3 (v1 + v2): " << v3 << std::endl;

    std::cout << std::endl;

    return 0;
}
