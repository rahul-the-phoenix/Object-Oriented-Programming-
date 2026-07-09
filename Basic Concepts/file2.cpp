#include<iostream>
#include<cmath>
using namespace std;

class calculator{

private:
	int a,b,c;

public:
	calculator(int a , int b , int c){
	this->a=a;    // use for name conflict as class has also the a,b,c and function has also a b c 
	this->b=b;  // this is a special pointer that points currect objects memory address for my case it is c1 
	this->c=c;
}

void display(){
	cout <<"numbers are : " << a <<" " << b << " "<< c << endl ;
}

void add(){
	cout << "addition result is : " << a+b+c << endl ;
}

void mul(){
	cout << "multiplication result is : " << a*b*c << endl;
}

void highest(){
if(a>=b && a>=c){ cout << "highest is " << a << endl ; }
 else if(b>=a && b>=c){ cout << "highest is " << b << endl ; }
else {
	cout << "highest is " << b << endl ;
}
}

void master (){    // for do every work in one calling name is master function 
	display();
	add();
	mul();
	highest();
}

//METHOD CHAINING PROCESS 

calculator& avarage (){
cout << "avarage result is : " << (a+b+c)/3 << endl ;
return *this;	
}

calculator& smallest(){   //object referrence not any answer  
cout << "smallest number is : " << min(a,min(a,b)) << endl ;
return *this;	 // return the current object so that s1.smallest().avarage() works
}

calculator& high(){
cout << "highest number is : " << max(a,max(b,c)) << endl ;
return *this;	
}


};

int main (){
 cout << " enter three numbers : " << endl;
 int a,b,c;
 cin >> a ;  cin >> b ; cin >> c;
  calculator c1(a,b,c);            //user defined object 
	 c1.display();
	 c1.add();
	 c1.mul();
	 c1.highest();
	 
	 
	 c1.master() ;      // master function for all works needed actually needed
	 c1.avarage().smallest().high();
}
