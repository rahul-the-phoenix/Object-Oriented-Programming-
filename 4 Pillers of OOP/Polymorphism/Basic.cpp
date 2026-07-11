Compile-time polymorphism is an OOP feature where the compiler selects and binds the appropriate function or operator 
to its implementation at the time of program compilation based on the number and type of arguments passed.

 
In C++, this is achieved through Function Overloading and Operator Overloading.
In java there is only method overloading not have operator overloading 


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







compile time polymorphism : Operator Overloading : to use operators ( + , = , - , * , << , >> ) as a function
remember : you cannot use this ( . (dot), .* (pointer to member), :: (scope resolution), ?: (ternary), and sizeof ) as a function
(JAVA does not support Operator Overloading )

Usecase : 
natural syntax: it lets you use standard symbols like + or - directly on custom objects, making your code look clean and like natural mathematics.
better readability: it eliminates the need to call clunky, long member functions (like c1.add(c2)), which keeps your codebase intuitive and highly readable.
 

#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    // constructor to initialize values
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

     // operator overloading using const reference
    // this allows passing temporary objects like Complex(4, 5)
   // syntax : return type operator +/-/*/% (const taking referrence of another class &class) 
    Complex operator + (const Complex& obj) { //for temporary object we must need const keyword , C++ offical rule to be sure that you cannot modify this 
        Complex temp;
        temp.real = real + obj.real; // adds real parts
        temp.imag = imag + obj.imag; // adds imaginary parts
        return temp;
    }


    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(4, 5); // represents 4 + 5i
    Complex c2(2, 3); // represents 2 + 3i

    Complex c3 = c1 + Complex(4, 5);    //temporary object delete just after its workdone
      Complex c4 = c1 + c2 ;     //created class 

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "result (c1 + c2) = "; c4.display();
    cout << "result (c1 + Complex(4,5)) = "; c3.display();


    return 0;  // c1 , c2 , c3  objects destroy here 
}
