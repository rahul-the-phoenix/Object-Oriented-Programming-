





#include <iostream>
using namespace std;

class AreaCalculator {
public:
    // square area: one int parameter
    int calculateArea(int side) {
        return side * side;
    }

    // rectangle area: two int parameters
    int calculateArea(int length, int breadth) {
        return length * breadth;
    }

    // circle area: one double parameter
    double calculateArea(double radius) {
        return 3.1416 * radius * radius;
    }
};

int main() {
    AreaCalculator cal;

    cout << "=== function overloading test ===" << endl;
    
    cout << "square area (side 5): " << cal.calculateArea(5) << endl;
    cout << "rectangle area (10 x 6): " << cal.calculateArea(10, 6) << endl;
    cout << "circle area (radius 4.5): " << cal.calculateArea(4.5) << endl;

    return 0;
}
