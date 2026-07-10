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


  
Types of Inheritance

Single Inheritance: A child class inherits from only one parent class. (A -> B)
Multiple Inheritance: A child class inherits from more than one parent class. (Note: C++ supports this, but Java does not support it directly to avoid ambiguity). (A, B -> C)
Multilevel Inheritance: A class is derived from another derived class. It acts like a grandfather-father-child relationship. (A -> B -> C)
Hierarchical Inheritance: Multiple child classes inherit from a single parent class. (A -> B and A -> C)
Hybrid Inheritance: A combination of two or more types of inheritance mentioned above (e.g., combining Multilevel and Multiple inheritance).
