What is Inheritance?
Inheritance is one of the core pillars of Object-Oriented Programming (OOP). In simple terms, it is a mechanism that allows 
a new class to acquire (or inherit) the properties (variables) and behaviors (methods/functions) of an existing class.
Base Class (or Parent/Super Class): The existing class whose features are inherited.
Derived Class (or Child/Sub Class): The new class that inherits the features from the base class.



Why Use Inheritance?

Code Reusability: Instead of writing the same code over and over again for different classes,
you can put the common code in a parent class and inherit it in child classes.

Method Overriding (Polymorphism): A child class can modify the behavior of a 
function inherited from the parent class to suit its specific needs.

Time and Effort Saving: It reduces development time, minimizes code redundancy, and leads to cleaner, shorter code.

Easy Maintenance: If a bug is found or an update is needed in the shared logic, you only need to change it once
in the parent class, and all child classes automatically get updated.



#include <iostream>
#include <string>
using namespace std;

// Base Class (Parent)
class Vehicle {
public:
    string brand;
    int speed;

    void startEngine() {
        cout << brand << "'s engine has started." << endl;
    }
};

// Derived Class 1 (Child of Vehicle)
class Car : public Vehicle {
public:
    int safetyAirbags;

    void drive() {
        cout << brand << " is driving smoothly at " << speed << " km/h with " 
             << safetyAirbags << " active airbags." << endl;
    }
};

// Derived Class 2 (Child of Vehicle)
class Motorcycle : public Vehicle {
public:
    bool hasSelfStart;

    void ride() {
        cout << brand << " is cruising at " << speed << " km/h. Self start available: " 
             << (hasSelfStart ? "Yes" : "No") << "." << endl;
    }
};

int main() {
    // 1. Creating a Car object
    Car myCar;
    myCar.brand = "Tesla";            // Inherited from Vehicle
    myCar.speed = 120;                // Inherited from Vehicle
    myCar.safetyAirbags = 6;          // Car's own property
    
    myCar.startEngine();              // Calling inherited function
    myCar.drive();                    // Calling own function
    
    cout << "------------------------------------------" << endl;

    // 2. Creating a Motorcycle object
    Motorcycle myBike;
    myBike.brand = "Yamaha";          // Inherited from Vehicle
    myBike.speed = 80;                // Inherited from Vehicle
    myBike.hasSelfStart = true;       // Motorcycle's own property
    
    myBike.startEngine();             // Calling inherited function
    myBike.ride();                    // Calling own function

    return 0;
}
