
 compile time polymorphism : Function Overloading 
 all the same functions if stay on the same class then it is Function Overloading 
 all the same fiontions if stay on parent or class then it is Runtime Polymorphism : Function Overridding
 all the same functions if stay on different independent class then it's not a polymorphism (a1.display() / b1.display() ) 



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
//  cout << "circle area (radius 4.5): " << cal.calculateArea(2,4,5,6) << endl;   //error as no function taking 4 eliments 

    return 0;
}
