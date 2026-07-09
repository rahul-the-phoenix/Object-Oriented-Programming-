#include<iostream>
#include<string>
using namespace std;


class account {
	private:
		string name;
		int account_no;
		int balance;
		 string village;
		 int *roi;
	
	public:
		
	// CONSTRUCTOR : the first function call after the object memory creation... name must be equal as class name  
	// special type of function that returns nothing , constructor must be n public sector
	// main workings : auto call , object value initialization  , memory or resource takin g dynamically 
	
		account(string name , int account_no , int balance){
			this->name= name ;
			this->account_no = account_no;          //parameterized constructor(having parameter) 
			this->balance = balance; 
		}
		
		account (){
			name = "SUKANYA";
			account_no = 7890;
			balance = 8000;
			//roi = new int[10000000000000000];   // this big ammount of ram allocation is not possible so , give the runtime error
			roi = new int[10000];  // allocation successful so will run the code 
		}
		
//		account(){     // default constructor ( no parameter , no argument )
//			
//		}
		
		account(string name , int balance ){     // parameterized constructor but having only 2 parameter 
			this->name= name ;
			this->balance = balance;
		}
		
//			account(account &b){
//			this->name= name ;
//			this->account_no = account_no;          //you can coping the function  using this also 
//			this->balance = balance; 
//		}	
//		
		 inline account(string a , int b , int c , string d ): name(a),account_no(b),balance(c), village(d){  // inline constructor , must have the word inline 
		}
		
	//=============================================================================================================================================================
	//=============================================================================================================================================================
	
	//destuctor destroy the object after workdone , it is the last function that is called for destroying  and free the resources or cleanup the memory 
	//it prevent memory leakages , name must be same as class name with a ~ sign in front , no return type 
	// not possible to pass a parameter in destructor , 1 class can have only 1 destructor (overload is not possible ) 

    ~account(){    //destructor
    	cout << " roi  is deleted ";
    		delete roi;   // delete dynamic memory 
	}
	
	
		void details(){
			cout  << "Details: "<< name << " " << account_no << " " << balance <<" " <<  "village: "  << village << endl;
		}
		
		
		void changename(string  name){
			this->name=name; 
		}
		
	};
	
	
	
	
	
	
	class myself {
		private :
			int number ;
		public :
			myself(int number){
				this->number = number ;
				cout <<"constructor is " << number << endl;
			}
			
			myself (){
				number = 5;
					cout <<"constructor is " << number << endl;
			}
			
		~myself(){
			cout << "destructor is : " << number << endl;
		}
	};
	
	 
		
   int main (){
   	account a1;
   	a1.details();         
	    
   	account a3("ram" , 123);
   	a3.details();          // account no is garbage values 
	    
   	a1.changename("RAHUL");   
   	a1.details();
   	account a2(a1);        // copy constructor copying a1 in a2 
   	a2.details();    // details of a2 
   	
   	account a5("RAHIM" , 1234 , 50000 , "MADHABPUR");
   	a5.details();
   	
   	account a6;
   	a6=a5;              // also can copy using this = 
   	a6.details();
   	
   	
   	
   	myself m1(1),m2(2),m3(3),m4(4); // construct in assendng order , destructed  in reverse order    
//   	myself *m5 = new myself;       // cheak this one time 
//   	delete m5;
   		return 0;
   }
