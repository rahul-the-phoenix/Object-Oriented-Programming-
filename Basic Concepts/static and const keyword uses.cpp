#include<iostream>
#include<string>
using namespace std;
class library {
 
	int no ;
	string name ;
	int rate;
	static int totalstudent ; // Only one copy exists in memory, which is shared by all objects of the class.
	//It belongs to the whole class, not to any specific object.
	
	public:
		
		library(int no , string name , int rate ){
			this->no=no;
			this->name= name ;
			this->rate = rate ;
			totalstudent ++ ;    //increasing or decreasing students 
		}
		
		static int gettotalstudent() {
        return totalstudent;  //function to get the totalstudent
    }
    
    void details(){
    	cout << no << " " << name << " " << rate << endl;
	}
};

// initialization must be done after the class ends    rule variable type classname :: variable = 0 ;
int library::totalstudent = 0;  //(:: is knowm as resolution operator)

int main (){
	library l1(1,"Rahul", 100);
	l1.details();
	cout << "total student = " << library::gettotalstudent() << endl; // no class needed for calling to get total student 
	
	library l2(2,"Lalu", 200);
	l2.details();
	cout << "total student = " << library::gettotalstudent() << endl; // total student can be get by using the class itself
	
	library l3(3,"Ruma", 300);
	l3.details();
	cout << "total student = " << library::gettotalstudent() << endl;
	
}

