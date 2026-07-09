//Encapsulation 
Definition of Encapsulation
Encapsulation is an object-oriented programming (OOP) concept that binds data (variables) and 
the methods (functions) that manipulate that data together into a single unit called a class.
It restricts direct access to some of an object's components, which is why it is often referred to as Data Hiding.

Why to Use Encapsulation?

Data Security & Protection: It prevents external code or unauthorized users from directly modifying 
or corrupting the internal state of an object (e.g., blocking someone from setting a book's price to a negative value.

Controlled Access: By using public getter and setter methods, you can enforce strict
validation rules before data is read or modified, maintaining absolute data integrity.

Code Maintainability: Since the internal implementation details are hidden, you can change
or update the internal code logic tomorrow without breaking any external code in the main() function.







#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;   //Encapsulation: binding data and functions together in a same class 
    double price;     //data hiding 
    bool isAvailable; // Restricted: Prevents manual bypassing of library rules

public:
    // Constructor: Safely initializes data on object creation
    Book(string bookTitle, double bookPrice) {
        title = bookTitle;
        isAvailable = true; // Book is available by default
        
        // Validation to ensure price is not negative
        if (bookPrice > 0) {
            price = bookPrice;      //real magic of Encapsulation 
        } else {
            price = 0.0;
        }
    }
    
    //display book title and rate 
    void display (){
    	cout << "Book name : " << title << " and rate is : " << price << endl;
	}

    // Public method to borrow a book (Business Logic)
    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Success: You have borrowed '" << title << "'." << endl;
        } else {
            cout << "Error: '" << title << "' is already checked out!" << endl;
        }
    }

    // Public method to return a book
    void returnBook() {
        isAvailable = true;
        cout << "Success: '" << title << "' has been returned." << endl;
    }

    // Setter method to validate and update price securely
    void updatePrice(double newPrice) {
        if (newPrice > 0) {
            price = newPrice;
            cout << "Price updated successfully to $" << price << endl;
        } else {
            cout << "Invalid action: Price cannot be negative or zero!" << endl;
        }
    }
};


int main() {
	
    // Creating an instance of an encapsulated Book object
    Book libraryBook("Data Structures & Algorithms", 45.99);
     libraryBook.display() ; //display name and price
     
    // 1. Attempting to borrow the same book twice (System validation catches this)
    libraryBook.borrowBook(); 
    libraryBook.borrowBook(); 

    // 2. Returning the book
    libraryBook.returnBook();

    // 3. Attempting to inject an invalid price (Rejected by the setter rule)
    libraryBook.updatePrice(-10.50); 
    
    libraryBook.updatePrice(1000.00);
    libraryBook.display() ;

    return 0;
}
