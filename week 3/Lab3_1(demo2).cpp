//title: lab3_1 (demo 2).cpp
//Abstract: Using classes, we output how much money an account has and then we add more money to the account.
//ID: 1507
//Name: Nicole Safty
//Date: 09/10/2021
#include <iostream>
using namespace std;

class Money{
private: 
int dollar;
int cent;

public:
  bool setAmount(int newDollar, int newCent);
  void output( );
void addAmount(int Adddollar, int Addcent);
};

int main() {
 Money m1, m2;   
  
 m1.setAmount(0, 0);  
m2.setAmount(25, 95);  

cout << "m1 output: ";  
m1.output();  
cout << "m2 output: ";  
m2.output();   

m1.addAmount(75, 9); 
m2.addAmount(30, 10);    

cout << "\n=== After addAmount() ===" << endl;    
cout << "m1 output: ";      
 m1.output();    
cout << "m2 output: ";
m2.output();    

return 0;
}

bool Money::setAmount(int newDollar, int newCent){
  dollar=newDollar;
  cent=newCent;
  if(dollar<0){ 
    cout<<"error: negative amount"<<endl;
    return false;
  }
if(cent>99||cent<0){
  cout<<"error: unstable amount"<<endl;
  return false;
}
return true;
}

void Money::output(){
  cout<<dollar<<" dollars and "<<cent<<" cents"<<endl;
}

void Money::addAmount(int Adddollar, int Addcent){
dollar+=Adddollar;
cent+=Addcent;

if(cent>=100){
  cent=cent-100;
  dollar=dollar+1;
}
}