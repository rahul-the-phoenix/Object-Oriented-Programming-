Types of Inheritance

Single Inheritance: A child class inherits from only one parent class. (A -> B)
Multiple Inheritance: A child class inherits from more than one parent class. (Note: C++ supports this, but Java does not support it directly to avoid ambiguity). (A, B -> C)
Multilevel Inheritance: A class is derived from another derived class. It acts like a grandfather-father-child relationship. (A -> B -> C)
Hierarchical Inheritance: Multiple child classes inherit from a single parent class. (A -> B and A -> C)
Hybrid Inheritance: A combination of two or more types of inheritance mentioned above (e.g., combining Multilevel and Multiple inheritance).


#include<iostream>
#include <string>
using namespace std;

// ============================================
// 1. BASE CLASS (Grandparent)
// ============================================
class LivingBeing {
public:
    string species;

    LivingBeing(string species) {
        this->species = species;
        cout << "LivingBeing constructor called!" << endl;
    }

    void breathe() {
        cout << species << " is breathing..." << endl;
    }
};

// ============================================
// 2. SINGLE INHERITANCE (A -> B) WITH VIRTUAL
// ============================================
class Human : virtual public LivingBeing {
public:
    string personality;
    int age;

    Human(string species, string personality, int age) 
        : LivingBeing(species) {
        this->personality = personality;
        this->age = age;
        cout << "Human constructor called!" << endl;
    }

    void think() {
        cout << personality << " human is thinking..." << endl;
    }
};

// ============================================
// 3. HIERARCHICAL INHERITANCE WITH VIRTUAL
// ============================================
class Male : virtual public Human {
public:
    int penis;

    // ? LivingBeing-? call ???? ???
    Male(string species, string personality, int age, int penis) 
        : LivingBeing(species),      // ? ??? ??? ?????
          Human(species, personality, age) {
        this->penis = penis;
        cout << "Male constructor called!" << endl;
    }

    void shave() {
        cout << "Male is shaving..." << endl;
    }
    
     void speak() {
        cout << "Male is speaking..." << endl;
    } 
};

class Female : virtual public Human {
public:
    int vagina;

    // ? LivingBeing-? call ???? ???
    Female(string species, string personality, int age, int vagina) 
        : LivingBeing(species),      // ? ??? ??? ?????
          Human(species, personality, age) {
        this->vagina = vagina;
        cout << "Female constructor called!" << endl;
    }

    void applyMakeup() {
        cout << "Female is applying makeup..." << endl;
    }
    
      void speak() {
        cout << "Female is speaking..." << endl;
    }  
};

// ============================================
// 4. MULTIPLE + HYBRID INHERITANCE
// ============================================
class Kinnar : public Male, public Female {
public:
    int dailyIncome;

    Kinnar(string species, string personality, int age, int penis, int vagina, int dailyIncome)
        : LivingBeing(species),
          Human(species, personality, age),
          Male(species, personality, age, penis),
          Female(species, personality, age, vagina) {
        this->dailyIncome = dailyIncome;
        cout << "Kinnar constructor called!" << endl;
    }

    void work() {
        cout << "Kinnar is earning " << dailyIncome << " taka daily..." << endl;
    }

    void showAllDetails() {
        cout << "\n===== KINNAR DETAILS =====" << endl;
        cout << "Species: " << species << endl;
        cout << "Personality: " << personality << endl;
        cout << "Age: " << age << endl;
        cout << "Penis: " << penis << " inch" << endl;
        cout << "Vagina: " << vagina << " inch" << endl;
        cout << "Daily Income: " << dailyIncome << " taka" << endl;
    }
};

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    cout << "========== 1. SINGLE INHERITANCE ==========" << endl;
    Human h1("Homo sapiens", "Friendly", 25);
    h1.think();
    h1.breathe();
    cout << endl;

    cout << "========== 2. HIERARCHICAL INHERITANCE ==========" << endl;
    Male m1("Homo sapiens", "Bold", 30, 5);
    m1.think();
    m1.shave();
    cout << endl;

    Female f1("Homo sapiens", "Innocent", 28, 8);
    f1.think();
    f1.applyMakeup();
    cout << endl;

    cout << "========== 3. MULTIPLE INHERITANCE ==========" << endl;
    cout << "========== 4. MULTILEVEL INHERITANCE ==========" << endl;
    cout << "========== 5. HYBRID INHERITANCE ==========" << endl;
    
    Kinnar k1("Homo sapiens", "Charming", 22, 4, 6, 500);
    
    k1.work();
    k1.think();
    k1.breathe();
    k1.shave();
    k1.applyMakeup();
    
    k1.showAllDetails();
    k1.Female::speak();
    k1.Male::speak();
    return 0;
}
