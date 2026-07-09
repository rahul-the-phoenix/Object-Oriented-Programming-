#include<iostream>
#include <string>
using namespace std;

class student {
private:
	string name;
	int roll;
	float marks;
	char grade;

//public:    //if marks is  not private means public then we can edit it by using s1.marks=-92.9 lke commands 
//float marks;

	
public: // public function , can be blank 
    
	student(string n , int r , float m){  //this is called constructor, it returns nothing, as same name as class , a class can have multiple constructor 
	name=n;       // constructor can be blank also like public , it has beed called autometically  
	roll=r;
	marks=m;
	//grade = (marks>=50)? 'A' : 'B';
	marks>=50 ? grade= 'A' : grade='B';      //ternary operator for grading
}

//public:   // we need manually data initalization in main function if constructor is blank 

void gradesystem(){
	cout << "grade: " << grade << endl ;
}
	
void displayname(){
	cout <<"name:" << name << endl;
}
float displaymarks(){
	cout << " current marks is : " << marks<< endl;
	return marks;
}
void setmarks(float newmarks){      // if want to edt the marks thhen you have to use these function
marks=newmarks;	
}

void setname(string newname){
	name=newname;
}

float getmarks(){
	return marks;
}

};

int main (){
	student s1("RAHUL", 20 , 89.7);     //s1, s2 , s3 , s4, s5 are object and student is class 
	s1.displaymarks();
	//s1.marks=49.2;      //compile time error as the marks is private 
	s1.setmarks(23.9);     // by using setmarks we can change the value of marks
	s1.displaymarks();
	//cout << s1.marks();  //marks is private so direct data excess is not even possible
	 cout << "marks of s1 is : " << s1.getmarks() << endl;
	
		student s[5] = {
	student ("ANISH", 58 , 80.7),
	student ("MUNDA", 30 , 28.7),
	student ("SOUMYA", 22 , 99.7),   // using array for large data set 
	student ("RINKI", 46 , 19.7),
	student ("RIKITA", 68 , 31.7)
};

	cout << "Details using array :\n ";
	for(int i = 0;i<=4;i++){
		s[i].displayname();
		s[i].displaymarks();
		s[i].gradesystem();
		//s[i].setmarks(s[i].marks()+10);   //can not axcess as marks is private , call the getmarks  that return the marks 
		s[i].setmarks(s[i].getmarks()+10);
		s[i].displaymarks();
	}
	
	
   student *me = new student("monali", 2 , 28);   //dynamic memory allocation in heap memory (as heap has large ammount of memory but stack has less ammount )
   (*me).displayname() ;   // new keyword use for dynamic memory allocation , creating object or variable in heap
   (*me).setname("debolina"); //object not destroy itself need delete keyword , where normal object delete automatcally 
   (*me).displayname() ;  //new create a heap memory for student class here and keep it's address in me here 
   (*me).gradesystem() ;
   delete me;	
	
	
	return 0;
}
