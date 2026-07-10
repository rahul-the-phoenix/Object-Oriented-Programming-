#include<iostream>
using namespace std;
class greedy{
	int a;   //int = 4 , char = 1 , float 4 , double 8 , bool 1 , string = character*1 but object fixed size is = 8 bytes
	int b;
	char c;  //greedy approach followed
	char d;    
	char e;   //  | a a a a |  | b b b b |  | c d e X |  (here X= padding , use for fast operation done )

};

class value{
	int a;
	char b; // | a a a a |  | b X X X |  | g g g g |  | s X X X |  | n n n n n n n n |
	int g;
	bool s;
	string n ;
}; 

int main (){
	greedy g1;
	value v1;
	cout << sizeof(g1);  //give us the memory used . for efficient use greedy approach 
	cout << sizeof(v1);
}
