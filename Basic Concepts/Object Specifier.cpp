#include <iostream>
#include <string>
using namespace std;

class Officer {
private:
    int salary = 50000; 

protected:
    string wife = "Mrinmoyee";              //within the class ( all acess possible ) all are allowed 

public:
    string rank = "Captain"; 

    //(Within the Same Class)
    void showAllDetailsWithinClass() {
        cout << "Salary (Private): " << salary << endl;      // (Yes)
        cout << "Wife (Protected): " << wife << endl;       //(Yes)
        cout << "Rank (Public): " << rank << endl;          //(Yes)
    }
};

int main() {
    Officer rahul;
    rahul.showAllDetailsWithinClass(); // no error

    // ============ CONTEXT: Outside the Class (main function) ============================

    // ১. Public (Allowed - YES)
    cout << "Rank: " << rahul.rank << endl; // value can be print 
    rahul.rank = "Major"; // value can be change 


    // ২. Private (Not Allowed - NO)
    // cout << rahul.salary; // ✗ COMPILER ERROR! 
    // rahul.salary = 70000; // ✗ COMPILER ERROR! (salary is private)          //outside the class (private / protected not allowed ) only publc allowed 


    // ৩. Protected (Not Allowed - NO)
    // cout << rahul.wife;   // ✗ COMPILER ERROR!
    // rahul.wife = "Neha";  // ✗ COMPILER ERROR! (wife is protected)
    return 0;
}







#include <iostream>
#include <string>
using namespace std;

// Base Class
class Officer {
private:
    int salary = 50000; // Hidden from everyone except Officer

protected:
    string wife = "Mrinmoyee"; // Hidden from main(), accessible to child classes

public:
    string rank = "Captain"; // Accessible to everyone
};

// Derived Class
class Rahul : public Officer {
public:
    void testInsideChildClass() {
        // Context: Inside a Derived Class

        // A) Public Member Access (Allowed)
        cout << "Rank from Parent: " << rank << endl; 
        rank = "Major";                                           //inside a child class (public and protected are allowed ) not private 

        // B) Protected Member Access (Allowed)
        cout << "Wife name from Parent: " << wife << endl; 
        wife = "Mrs. Manna"; 

        // C) Private Member Access (Not Allowed)
        // cout << salary; // COMPILER ERROR: Private to Parent
        // salary = 80000; // COMPILER ERROR: Private to Parent
    }
};

int main() {
    Rahul r;
    r.testInsideChildClass();
    return 0;
}
